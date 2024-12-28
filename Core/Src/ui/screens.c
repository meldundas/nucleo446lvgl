#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff626b6d), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff9e9e9e), LV_PART_SCROLLBAR | LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // background
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.background = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_background);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 84, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ECET 260");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe6e7e0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // led
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.led = obj;
            lv_obj_set_pos(obj, 265, 13);
            lv_obj_set_size(obj, 32, 32);
            lv_led_set_color(obj, lv_color_hex(0xff0000ff));
            lv_led_set_brightness(obj, 255);
        }
        {
            // blueButton
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.blue_button = obj;
            lv_obj_set_pos(obj, 60, 169);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_led_event, LV_EVENT_PRESSED, (void *)66);
            lv_obj_add_event_cb(obj, action_led_event, LV_EVENT_RELEASED, (void *)66);
            add_style_button_style(obj);
            lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Button");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff0639b4), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // greenButton
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.green_button = obj;
            lv_obj_set_pos(obj, 60, 111);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_led_event, LV_EVENT_PRESSED, (void *)71);
            lv_obj_add_event_cb(obj, action_led_event, LV_EVENT_RELEASED, (void *)71);
            add_style_button_style(obj);
            lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff4c913e), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Button");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff0fee0d), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // redButton
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.red_button = obj;
            lv_obj_set_pos(obj, 60, 54);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_led_event, LV_EVENT_PRESSED, (void *)82);
            lv_obj_add_event_cb(obj, action_led_event, LV_EVENT_RELEASED, (void *)82);
            add_style_button_style(obj);
            lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffdc44c7), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // redlabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.redlabel = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "RED");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffe80e0e), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // ledoff
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.ledoff = obj;
            lv_obj_set_pos(obj, 197, 86);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ledoff);
        }
        {
            // ledon
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.ledon = obj;
            lv_obj_set_pos(obj, 197, 86);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ledon);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void tick_screen_main() {
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
