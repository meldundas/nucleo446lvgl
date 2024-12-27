#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "screens.h"

//
// Style: buttonStyle
//

void init_style_button_style_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_pad_top(style, 10);
    lv_style_set_pad_bottom(style, 10);
    lv_style_set_pad_left(style, 16);
    lv_style_set_pad_right(style, 16);
    lv_style_set_bg_color(style, lv_color_hex(0xff097ad3));
    lv_style_set_border_width(style, 3);
    lv_style_set_border_color(style, lv_color_hex(0xff0822b8));
    lv_style_set_border_side(style, LV_BORDER_SIDE_FULL);
    lv_style_set_arc_rounded(style, true);
};

lv_style_t *get_style_button_style_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_style_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_button_style(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_button_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_button_style(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_button_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_button_style,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_button_style,
    };
    remove_style_funcs[styleIndex](obj);
}

