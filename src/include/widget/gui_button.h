/**	
 * \file            gui_button.h
 * \brief           Button widget
 */
 
/*
 * Copyright (c) 2017 Tilen Majerle
 *  
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, 
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Author:          Tilen Majerle <tilen@majerle.eu>
 */
#ifndef __GUI_BUTTON_H
#define __GUI_BUTTON_H

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif
    
/**
 * \addtogroup      GUI_WIDGETS
 * \{
 */
    
#include "gui_widget.h"

/**
 * \defgroup        GUI_BUTTON Button
 * \brief           Button which can be pressed
 * \{
 * 
 * Button represents simple widget which can be pressed and can process events such as click, long click or double click.
 * 
 * \image html image_widget_button.png Default button state with text
 */

/**
 * \brief           Button color list enumeration
 */
typedef enum GUI_BUTTON_COLOR_t {
    GUI_BUTTON_COLOR_BG = 0x00,             /*!< Background color index */
    GUI_BUTTON_COLOR_FG,                    /*!< Foreground color index */
    GUI_BUTTON_COLOR_BORDER,                /*!< Border color index in array */
} GUI_BUTTON_COLOR_t;

#if defined(GUI_INTERNAL) || __DOXYGEN__
/**
 * \brief           GUI button structure
 */
typedef struct GUI_BUTTON_t {
    GUI_HANDLE C;                           /*!< GUI handle object, must always be first on list */
    
    GUI_Dim_t BorderWidth;                  /*!< Border width */
    GUI_Dim_t BorderRadius;                 /*!< Border radius */
} GUI_BUTTON_t;
#endif /* defined(GUI_INTERNAL) || __DOXYGEN__ */

GUI_HANDLE_p gui_button_create(GUI_ID_t id, GUI_iDim_t x, GUI_iDim_t y, GUI_Dim_t width, GUI_Dim_t height, GUI_HANDLE_p parent, GUI_WIDGET_CALLBACK_t cb, uint16_t flags);
uint8_t gui_button_setcolor(GUI_HANDLE_p h, GUI_BUTTON_COLOR_t index, GUI_Color_t color);
uint8_t gui_button_setborderradius(GUI_HANDLE_p h, GUI_Dim_t size);
    
/**
 * \}
 */
 
/**
 * \}
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /* __GUI_BUTTON_H */
