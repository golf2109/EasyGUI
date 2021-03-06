/**	
 * \file            gui_input.h
 * \brief           Input manager
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
#ifndef __GUI_INPUT_H
#define __GUI_INPUT_H

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup        GUI_INPUT Input manager
 * \brief           Input methods to communicate with user
 * \{
 */
#include "gui/gui.h"
    
uint8_t gui_input_touchadd(GUI_TouchData_t* ts);
uint8_t gui_input_keyadd(GUI_KeyboardData_t* kb);

#if !__DOXYGEN__ && defined(GUI_INTERNAL)
void gui_input_init(void);
uint8_t gui_input_touchavailable(void);
uint8_t gui_input_touchread(GUI_TouchData_t* ts);
uint8_t gui_input_keyread(GUI_KeyboardData_t* kb);
#endif /* !__DOXYGEN__ && defined(GUI_INTERNAL) */

/**
 * \}
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /* __GUI_INPUT_H */
