// Created on: 2011-10-25
// Created by: Sergey ZERCHANINOV
// Copyright (c) 2011-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#include <OpenGl_GlCore11.hxx>

#include <OpenGl_LineAttributes.hxx>
#include <OpenGl_Context.hxx>

IMPLEMENT_STANDARD_RTTIEXT(OpenGl_LineAttributes,OpenGl_Resource)

static const unsigned int myInteriors[TEL_HS_USER_DEF_START][32] =
{
  //TEL_HS_SOLID
  {
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF
  },
  //TEL_HS_CROSS
  {
    0xFFFFFFFF,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB,
    0xEEEEEEEE,
    0xBBBBBBBB
  },
  //TEL_HS_CROSS_SPARSE
  {
    0x81818181,
    0x24242424,
    0x18181818,
    0x42424242,
    0x81818181,
    0x24242424,
    0x18181818,
    0x42424242,
    0x81818181,
    0x24242424,
    0x18181818,
    0x42424242,
    0x81818181,
    0x24242424,
    0x18181818,
    0x42424242,
    0x81818181,
    0x24242424,
    0x18181818,
    0x42424242,
    0x81818181,
    0x24242424,
    0x18181818,
    0x42424242,
    0x81818181,
    0x24242424,
    0x18181818,
    0x42424242,
    0x81818181,
    0x24242424,
    0x18181818,
    0x42424242
  },
  //TEL_HS_GRID
  {
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888,
    0xFFFFFFFF,
    0x88888888
  },
  //TEL_HS_GRID_SPARSE
  {
    0xFFFFFFFF,
    0x80808080,
    0x80808080,
    0x80808080,
    0xFFFFFFFF,
    0x80808080,
    0x80808080,
    0x80808080,
    0xFFFFFFFF,
    0x80808080,
    0x80808080,
    0x80808080,
    0xFFFFFFFF,
    0x80808080,
    0x80808080,
    0x80808080,
    0xFFFFFFFF,
    0x80808080,
    0x80808080,
    0x80808080,
    0xFFFFFFFF,
    0x80808080,
    0x80808080,
    0x80808080,
    0xFFFFFFFF,
    0x80808080,
    0x80808080,
    0x80808080,
    0xFFFFFFFF,
    0x80808080,
    0x80808080,
    0x80808080
  },
  //TEL_HS_DIAG_45
  {
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222,
    0x88888888,
    0x22222222
  },
  //TEL_HS_DIAG_135
  {
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444,
    0x11111111,
    0x44444444
  },
  //TEL_HS_HORIZONTAL
  {
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0x00000000
  },
  //TEL_HS_VERTICAL
  {
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111,
    0x11111111
  },
  //TEL_HS_DIAG_45_SPARSE
  {
    0x80808080,
    0x20202020,
    0x08080808,
    0x02020202,
    0x80808080,
    0x20202020,
    0x08080808,
    0x02020202,
    0x80808080,
    0x20202020,
    0x08080808,
    0x02020202,
    0x80808080,
    0x20202020,
    0x08080808,
    0x02020202,
    0x80808080,
    0x20202020,
    0x08080808,
    0x02020202,
    0x80808080,
    0x20202020,
    0x08080808,
    0x02020202,
    0x80808080,
    0x20202020,
    0x08080808,
    0x02020202,
    0x80808080,
    0x20202020,
    0x08080808,
    0x02020202
  },
  //TEL_HS_DIAG_135_SPARSE
  {
    0x01010101,
    0x04040404,
    0x10101010,
    0x40404040,
    0x01010101,
    0x04040404,
    0x10101010,
    0x40404040,
    0x01010101,
    0x04040404,
    0x10101010,
    0x40404040,
    0x01010101,
    0x04040404,
    0x10101010,
    0x40404040,
    0x01010101,
    0x04040404,
    0x10101010,
    0x40404040,
    0x01010101,
    0x04040404,
    0x10101010,
    0x40404040,
    0x01010101,
    0x04040404,
    0x10101010,
    0x40404040,
    0x01010101,
    0x04040404,
    0x10101010,
    0x40404040
  },
  //TEL_HS_HORIZONTAL_SPARSE
  {
    0xFFFFFFFF,
    0x00000000,
    0x00000000,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0x00000000,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0x00000000,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0x00000000,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0x00000000,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0x00000000,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0x00000000,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0x00000000,
    0x00000000
  },
  //TEL_HS_VERTICAL_SPARSE
  {
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010,
    0x10101010
  }
};


// =======================================================================
// function : OpenGl_LineAttributes
// purpose  :
// =======================================================================
OpenGl_LineAttributes::OpenGl_LineAttributes()
: myPatternBase(0)
{
  //
}

// =======================================================================
// function : ~OpenGl_LineAttributes
// purpose  :
// =======================================================================
OpenGl_LineAttributes::~OpenGl_LineAttributes()
{
  Release (NULL);
}

// =======================================================================
// function : Release
// purpose  :
// =======================================================================
void OpenGl_LineAttributes::Release (OpenGl_Context* theGlCtx)
{
  // Delete surface patterns
  if (myPatternBase != 0)
  {
    if (theGlCtx->IsValid())
    {
    #if !defined(GL_ES_VERSION_2_0)
      glDeleteLists ((GLuint )myPatternBase, TEL_HS_USER_DEF_START);
    #endif
    }
    myPatternBase = 0;
  }
}

// =======================================================================
// function : Init
// purpose  :
// =======================================================================
void OpenGl_LineAttributes::Init (const Handle(OpenGl_Context)& theGlCtx)
{
  // Return if already initialized
  if (myPatternBase != 0)
  {
    return;
  }

#if !defined(GL_ES_VERSION_2_0)
  if (theGlCtx->core11 == NULL)
  {
    return;
  }

  // GL_POLYGON_STIPPLE need 32x32 stipple patterns
  const int nbi = sizeof(myInteriors) / (32 * sizeof(unsigned int));
  myPatternBase = glGenLists(TEL_HS_USER_DEF_START);
  for (int i = 1; i < TEL_HS_USER_DEF_START; i++)
  {
    glNewList ((GLuint )myPatternBase + i, GL_COMPILE);
    glPolygonStipple ((const GLubyte* )myInteriors[i < nbi ? i : 0]);
    glEndList();
  }
#else
  (void )theGlCtx;
#endif
}

// =======================================================================
// function : SetTypeOfHatch
// purpose  :
// =======================================================================
void OpenGl_LineAttributes::SetTypeOfHatch (const int theType) const
{
#if !defined(GL_ES_VERSION_2_0)
  if (myPatternBase == 0)
  {
    return;
  }

  if (theType != 0)
  {
    glCallList ((GLuint )myPatternBase + (GLuint )theType);
    glEnable (GL_POLYGON_STIPPLE);
  }
  else
    glDisable (GL_POLYGON_STIPPLE);
#else
  (void )theType;
#endif
}
