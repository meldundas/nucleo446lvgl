#include "../../lv_examples.h"
#if LV_BUILD_EXAMPLES
#if LV_USE_SVG && LV_USE_VECTOR_GRAPHIC

/**
 * Load an SVG data
 */
static void event_cb(lv_event_t * e)
{
    static char svg_data[] = "<svg width=\"6cm\" height=\"4cm\" viewBox=\"0 0 320 240\">"
                             "<circle cx=\"160\" cy=\"2\" r=\"20\" fill=\"blue\" stroke=\"blue\" stroke-width=\"2\"/></svg>";

    lv_layer_t * layer = lv_event_get_layer(e);
    lv_svg_node_t * svg = lv_svg_load_data(svg_data, sizeof(svg_data) / sizeof(char));
    lv_draw_svg(layer, svg);
    lv_svg_node_delete(svg);
}

void lv_example_svg_1(void)
{
    lv_obj_add_event_cb(lv_screen_active(), event_cb, LV_EVENT_DRAW_MAIN, NULL);
}
#else

void lv_example_svg_1(void)
{
    /*TODO
     *fallback for online examples*/

    lv_obj_t * label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, "SVG is not enabled");
    lv_obj_center(label);
}

#endif
#endif
