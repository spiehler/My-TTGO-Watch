/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#include "config.h"
#include <TTGO.h>

#include "calendar.h"
#include "calendar_db.h"
#include "calendar_overview.h"

#include "gui/mainbar/mainbar.h"
#include "gui/icon.h"
#include "gui/statusbar.h"
#include "gui/app.h"
#include "gui/widget_factory.h"
#include "gui/widget_styles.h"

#include "utils/alloc.h"
/**
 * app icon
 */
icon_t *calendar_icon = NULL;                                       /** @brief calendar icon */
LV_IMG_DECLARE(calendar_64px);                                      /** @brief calendar icon image */

static void calendar_enter_event_cb( lv_obj_t * obj, lv_event_t event );
/**
 * setup routine for application
 */
void calendar_app_setup( void ) {
    /**
     * register app icon on the app tile
     */
    calendar_icon = app_register( "Calendar\n(alpha)", &calendar_64px, calendar_enter_event_cb );
    /**
     * check and init database
     */
    calendar_db_setup();
    /**
     * setup calendar overview
     */
    calendar_overview_setup();
}

static void calendar_enter_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):
               mainbar_jump_to_tilenumber( calendar_overview_get_tile(), LV_ANIM_OFF );
               statusbar_hide( true );
               break;
    }
}
