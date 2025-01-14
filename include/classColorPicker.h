﻿#pragma once
#include <lvgl.h>
#include <classTile.h>

class classColorPicker

{
private:
  classTile* _callingTile = NULL;
  lv_obj_t* _parent = NULL;
  lv_obj_t *_ovlPanel = NULL;
  lv_obj_t *_panelRGB = NULL;
  lv_obj_t *_panelCCT = NULL;
  lv_obj_t *_btnExit = NULL;
  lv_obj_t *_colorWheel = NULL;
  lv_obj_t *_labelKelvin = NULL;
  lv_obj_t *_labelKelvinValue = NULL;
  lv_obj_t *_labelBrightnessColor = NULL;
  lv_obj_t *_labelBrightnessColorValue = NULL;
  lv_obj_t *_labelBrightnessWhite = NULL;
  lv_obj_t *_labelBrightnessWhiteValue = NULL;
  lv_obj_t *_panelKelvin = NULL;
  lv_obj_t *_barKelvinLow = NULL;
  lv_obj_t *_barKelvinHigh = NULL;
  lv_obj_t *_sliderKelvin = NULL;
  lv_obj_t *_barBrightnessColor = NULL;
  lv_obj_t *_sliderBrightnessColor = NULL;
  lv_obj_t *_barBrightnessWhite = NULL;
  lv_obj_t *_sliderBrightnessWhite = NULL;
  lv_obj_t *_panelPreview = NULL;
  lv_obj_t *_labelCursor = NULL;
  lv_obj_t *_imgCursor = NULL;
  lv_obj_t *_btnColor = NULL;
  lv_obj_t *_btnKelvin = NULL;
  lv_obj_t *canvas = NULL;
  lv_obj_t *_panelCursor = NULL;
  lv_obj_t *_imgCw = NULL;
  lv_obj_t *_panelCwFrame = NULL;

  void _createColorPicker(lv_img_dsc_t *imgCw);
  static void _exitButtonEventHandler(lv_event_t *e);


public:
  classColorPicker(void){};
  classColorPicker(classTile *tile, lv_event_cb_t colorPickerEventHandler, lv_event_cb_t ColorPickerCwEventHandler, lv_img_dsc_t *imgCw, int cpMode);
  classTile* getTile(void);
  void close(void);
  bool isActive(void);
  void updateAll(void);
  void updateCw(lv_point_t point, int mode);
  void updatePanelRGB(lv_color32_t rgb);
  void switchMode(int cpMode);
};
