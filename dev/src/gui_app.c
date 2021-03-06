/**
 * \file            gui_app.c
 * \brief           GUI application
 */

#include "app.h"

/* Touch data structure */
TM_TOUCH_t TS;

GUI_Dim_t lcd_width, lcd_height;

/**
 * \brief           Creates desktop with GUI
 */
void
create_desktop(void) {
    GUI_HANDLE_p winbase;
    
    lcd_width = gui_lcd_getwidth();
    lcd_height = gui_lcd_getheight();
    
    gui_widget_setfontdefault(&GUI_Font_Arial_Narrow_Italic_22);
    
    winbase = gui_window_getdesktop();          /* Get desktop window */
    if (winbase != NULL) {
        /* Create status bar */
        gui_container_create(GUI_ID_CONTAINER_STATUS, 0, 0, lcd_width, 40, NULL, gui_container_callback, 0);
    }
    open_container(GUI_ID_CONTAINER_WIFI);      /* Open WiFi container */
}

/**
 * \brief           Open container with specific ID on main page
 * \param[in]       id: Container ID to open
 */
void
open_container(GUI_ID_t cont_id) {
    GUI_HANDLE_p h;
    
    gui_widget_hidechildren(gui_window_getdesktop());   /* Hide all widgets on desktop first */
    gui_widget_show(gui_widget_getbyid(GUI_ID_CONTAINER_STATUS));
    
    h = gui_widget_getbyid(cont_id);            /* Get widget by ID */
    if (h == NULL) {
        h = gui_container_create(cont_id, 0, 40, lcd_width, lcd_height - 40, NULL, gui_container_callback, 0);
    }
    gui_widget_show(h);                         /* Show widget */
    gui_widget_putonfront(h);                   /* Put widget to most visible area */
}

/**
 * \brief           Read touch from screen and notify GUI
 */
void
read_touch(void) {
    static GUI_TouchData_t p = {0}, t = {0};
    uint8_t i, update = 0, diffx, diffy;
    TM_TOUCH_Read(&TS);                         /* Read touch data */
    
    memset((void *)&t, 0x00, sizeof(t));
    t.Status = TS.NumPresses ? GUI_TouchState_PRESSED : GUI_TouchState_RELEASED;
    t.Count = TS.NumPresses > GUI_CFG_TOUCH_MAX_PRESSES ? GUI_CFG_TOUCH_MAX_PRESSES : TS.NumPresses;
    for (i = 0; i < t.Count; i++) {
        t.X[i] = TS.X[i];
        t.Y[i] = TS.Y[i];
    }
    if (t.Count != p.Count) {
        update = 1;
    } else {
        for (i = 0; i < t.Count; i++) {
            diffx = GUI_ABS(p.X[i] - t.X[i]);
            diffy = GUI_ABS(p.Y[i] - t.Y[i]);
            if (diffx > 2 || diffy > 2) {
                update = 1;
                break;
            }
        }
    }
    
    /* Check differences */
    if (update || (t.Status == GUI_TouchState_RELEASED && p.Status != GUI_TouchState_RELEASED)) {
        gui_input_touchadd(&t);
    }
    memcpy(&p, &t, sizeof(p));
}
