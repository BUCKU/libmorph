/******************************************************************************

    libmorphrus - dictiorary-based morphological analyser for Russian.
    Copyright (C) 1994-2016 Andrew Kovalenko aka Keva

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

    Commercial license is available upоn request.

    Contacts:
      email: keva@meta.ua, keva@rambler.ru
      Skype: big_keva
      Phone: +7(495)648-4058, +7(926)513-2991

******************************************************************************/
# if !defined( _mlmadefs_h_ )
# define _mlmadefs_h_

// Определить кроссплатформенные типы данных
# include "../include/mlma1049.h"
# include <xmorph/typedefs.h>

# if defined( LIBMORPH_NAMESPACE )
namespace LIBMORPH_NAMESPACE
{
# endif   // LIBMORPH_NAMESPACE

  # define ffNNext       0x80              /* Nesessary-next flex-item level         */
  # define ffONext       0x40              /* Optional-next flex-item level          */

  # define wfPostSt   0x8000       /* Stem has post-text definition          */
  # define wfMixTab   0x4000       /* Stem has mix-table reference           */
  # define wfFlexes   0x2000       /* Stem has flex-table reference          */
  # define wfOldWord  0x0080       /* Old word, at most not used now         */

  // Глобальные данные, которые никто не трогает

  extern unsigned char  flexTree[];
  extern unsigned char  mxTables[];
  extern unsigned char  mixTypes[];
  extern unsigned char  classmap[];
  extern unsigned char  stemtree[];
  extern unsigned char  lidstree[];

  extern  unsigned      pspMinCapValue[];

  // Макроопределения для вычисления легальной ступени чередования

  inline int  GetVerbMixPowerType3( word16_t gramInfo )
  {
    int   vtense = gramInfo & gfVerbTime;

    return ( (vtense == vtPresent) || ( vtense == vtFuture) ? 2 : 1 );
  }

  inline int  GetVerbMixPowerType2( word16_t gramInfo )
  {
    int   vtense = gramInfo & gfVerbTime;
    bool  passiv = (gramInfo & gfVerbForm) == vfVerbPassiv;

    return ( (vtense == vtPast) && passiv ? 3 :
           ( (vtense != vtPast) && (vtense != vtInfinitiv) ? 2 : 1 ) );
  }

  inline int  GetVerbMixPowerType1( word16_t gramInfo )
  {
    return ( (gramInfo & (gfVerbTime|gfVerbForm)) == (vtPast|vfVerbPassiv) ? 3 :
           ( (gramInfo & (gfVerbFace|gfMultiple)) == vbFirstFace ? 2 : 1 ) );
  }

  inline int  GetVerbMixPower( word16_t stemInfo, word16_t gramInfo )
  {
    int   mixType = (stemInfo & 0x0300) >> 8;

    return ( mixType == 0 ? GetVerbMixPowerType1( gramInfo ) :
           ( mixType == 1 ? GetVerbMixPowerType2( gramInfo ) :
           ( mixType == 2 ? GetVerbMixPowerType3( gramInfo ) : 1 ) ) );
  }

    #define MascNotAnimMixPower(GramInfo)   \
      (((((GramInfo) & (gfFormMask | gfMultiple)) == 0) || (((GramInfo) & (gfFormMask | gfMultiple)) == (3 << 12))) ? 1 : 2)

    #define MascAnimateMixPower(GramInfo)   \
      ((((GramInfo) & (gfFormMask | gfMultiple)) == 0) ? 1 : 2)

    #define MascMixedMixPower(GramInfo, AFlags)   \
      ((((AFlags) & afAnimated) != 0) ? MascAnimateMixPower((GramInfo)) :  \
        MascNotAnimMixPower((GramInfo)))

    #define FemnNotAnimMixPower(GramInfo)   \
      ((((GramInfo) & (gfFormMask | gfMultiple)) == ((1 << 12) | gfMultiple)) ? 2 : 1)

    #define FemnAnimateMixPower(GramInfo)   \
      (((((GramInfo) & (gfFormMask | gfMultiple)) == ((1 << 12) | gfMultiple)) || \
        (((GramInfo) & (gfFormMask | gfMultiple)) == ((3 << 12) | gfMultiple))) ? 2 : 1)

    #define FemnMixedMixPower(GramInfo, AFlags)   \
      ((((AFlags) & afAnimated) != 0) ? FemnAnimateMixPower((GramInfo)) :  \
        FemnNotAnimMixPower((GramInfo)))

    #define GetAdjectivMixPower(GramInfo)   \
      (((GramInfo) == gfCompared) ? 3 :       \
       (((GramInfo) == ((1 << 9) | gfShortOne)) ? 2 : 1))

  // stem access class

  struct  steminfo
  {
    word16_t        wdinfo;
    word16_t        tfoffs;
    word16_t        mtoffs;

  public:     // init
    steminfo( const byte_t* pclass = NULL )
      {
        if ( pclass != NULL )
          Load( pclass );
      }
    steminfo& Load( const byte_t* pclass )
      {
        wdinfo = getword16( pclass );
        tfoffs = (wdinfo & wfFlexes) != 0 || (wdinfo & 0x3f) == 51 ? getword16( pclass ) : 0;
        mtoffs = (wdinfo & wfMixTab) != 0 ? getword16( pclass ) : 0;
        return *this;
      }
    unsigned      MinCapScheme() const
      {
        return pspMinCapValue[wdinfo & 0x3f];
      }
    const byte_t* GetFlexTable() const
      {
        return tfoffs != 0 && (wdinfo & 0x3f) != 51 ? (tfoffs << 0x0004) + flexTree : NULL;
      }
    const byte_t* GetSwapTable() const
      {
        return mtoffs != 0 ? mtoffs + mxTables : NULL;
      }
    int           GetSwapLevel( word16_t grinfo, byte_t bflags ) const
      {
        switch ( mixTypes[wdinfo & 0x3F] )
        {
          case 1:   return GetVerbMixPower( wdinfo, grinfo );
          case 2:   return MascNotAnimMixPower( grinfo );
          case 3:   return MascAnimateMixPower( grinfo );
          case 4:   return MascMixedMixPower( grinfo, bflags );
          case 5:   return FemnNotAnimMixPower( grinfo );
          case 6:   return FemnAnimateMixPower( grinfo );
          case 7:   return FemnMixedMixPower( grinfo, bflags );
          case 8:   return GetAdjectivMixPower( grinfo );
          default:  return 1;
        }
      }
  };

  // Некоторые полезные функции, выясняющие часть речи

  inline  bool  IsVerb( word16_t wbInfo )
  {
    return (wbInfo & 0x3F) <= 6;
  }

  inline  bool  IsAdjective( word16_t wbInfo )
  {
    wbInfo &= 0x3F;

    return (wbInfo >= 25 && wbInfo <= 28) || wbInfo == 34 || wbInfo == 36 || wbInfo == 42;
  }

  inline  bool  IsParticiple( word16_t grInfo )
  {
    return (grInfo & gfVerbForm) == vfVerbActive || (grInfo & gfVerbForm) == vfVerbPassiv;
  }

  //=====================================================================
  // Meth: GetNormalInfo
  // Функция строит грамматическую информацию о нормальной форме слова,
  // используя тип этого слова, грамматическую информацию об отождествлении
  // и настройки поиска и нормализации.
  // Нормальной формой считается:
  // Для существительных - именительный падеж единственного числа;
  // Для прилагательных - именительный падеж мужского рода;
  // Для глаголов - инфинитив (или причастная форма - по настройкам).
  //=====================================================================
  inline word16_t GetNormalInfo( word16_t wbInfo,
                                 word16_t grInfo,
                                 unsigned nFlags )
  {
    word16_t  nfInfo = 0;

    if ( IsVerb( wbInfo ) )
    {
      nfInfo = vtInfinitiv;
      if ( ( nFlags & nfAdjVerbs ) && IsParticiple( grInfo ) )
        nfInfo = (word16_t)((grInfo & (gfVerbTime|gfVerbForm)) | (1 << 9));
    }
      else
    if ( IsAdjective( wbInfo ) )
      nfInfo = 1 << 9;
    if ( wbInfo & wfMultiple )
      nfInfo |= gfMultiple;
    return nfInfo;
  }

# if defined( LIBMORPH_NAMESPACE )
} // end namespace
# endif   // LIBMORPH_NAMESPACE

# endif // _mlmadefs_h_
