﻿#pragma once
#include <lvgl.h>
#include <globalDefines.h>

class classTile
{
protected:
  lv_obj_t *_parent = NULL;
  lv_obj_t *_btn = NULL;
  lv_obj_t *_label = NULL;
  lv_obj_t *_subLabel = NULL;
  lv_obj_t *_linkedLabel = NULL;
  lv_obj_t *_unitLabel = NULL;
  lv_obj_t *_numLabel = NULL;
  lv_obj_t *_btnUp = NULL;
  lv_obj_t *_btnDown = NULL;
  lv_obj_t *_ovlPanel = NULL;
  lv_obj_t *_bar = NULL;
  lv_obj_t *_txtIconText = NULL;
  lv_obj_t *_dropDown = NULL;
  lv_obj_t *_dropDownList = NULL;
  lv_obj_t *_dropDownLabel = NULL;
  lv_obj_t *_imgBg = NULL;
  lv_obj_t *_roller = NULL;

  int _screenIdx = 0;
  int _tileIdx = 0;
  int _style = 0;
  string _styleStr;
  int _linkedScreen = 0;
  bool _state = false;
  bool _keyPadEnable = false;
  int _levelStart = 0;
  int _levelStop = 100;
  int _levelLargeStep = 5;
  int _level = 0;
  bool _topDownMode = false;
  const void *_img = NULL;
  const void *_imgOn = NULL;
  const void *_imgConfig = NULL;
  const void *_imgOnConfig = NULL;
  uint16_t _dropDownIndex = 0;
  int _selectorIndex = 0;
  string _selectorList = "";
  lv_color32_t _colorPickerRGB32 = {255, 255, 255};
  int _colorPickerKelvin = 4000;
  int _colorPickerBrightnessWhite = 50;
  int _colorPickerMode = CP_MODE_COLOR;

  void _button(lv_obj_t *parent, const void *img);
  void _reColorAll(lv_color_t color, lv_style_selector_t selector);
  void _setIconTextFromIndex(void);
  void _freeImageHeap();

public :
  tileId_t tileId;
  lv_obj_t *btn = NULL;

  classTile(void){};
  classTile(lv_obj_t *parent, const void *img);
  classTile(lv_obj_t *parent, const void *img, const char *labelText);
  ~classTile();

  void begin(lv_obj_t *parent, const void *img, const char *labelText);
  void registerTile(int screenIdx, int tileIdx, int style, const char* styleStr);
  void setLabel(const char *labelText);
  void setSubLabel(const char *subLabelText);
  void setState(bool state);
  lv_color_t getColor();
  void setColor(lv_color_t color);
  void setColor(int r, int g, int b);
  void setIcon(const void *imgIcon);
  void setNumber(const char *number, const char *units);
  void setBgImage(lv_img_dsc_t *img);
  void alignBgImage(int zoom, int posOffsX, int posOffsY, int angle);
  void setLink(int linkedScreen);
  void setKeyPadEnable(bool enable);
  void setIconForStateOn(const void* imgStateOn);
  void setIconText(const char *iconText);
  void getImages(const void* &imgOff, const void* &imgOn);

  int getLink(void);
  bool getKeyPadEnable(void);
  tileId_t getId(void);
  int getScreenIdx(void);
  int getTileIdx(void);
  int getStyle(void);
  const char* getStyleStr(void);
  bool getState(void);
  char *getLabel(void);
  
  void addEventHandler(lv_event_cb_t callBack);

  void setLevelStartStop(int start, int stop);
  void setLevel(int level, bool force);
  int getLevel(void);
  int getLevelStart(void);
  int getLevelStop(void);
  int getLevelLargeStep(void);
  void setTopDownMode(bool enable);
  void showOvlBar(int level);
  void addUpDownControl(lv_event_cb_t upDownEventHandler, const void* imgUpperButton, const void* imgLowerButton);
 
  void setDropDownList(const char *list);
  void setDropDownIndex(uint16_t index);
  void setDropDownLabel(const char *label);
  const char *getDropDownList(void);
  uint16_t getDropDownIndex(void);
  const char *getDropDownLabel(void);
  void setDropDownIndicator(void);

  void setSelectorList(const char* list);
  void showSelector(int index);
  void setSelectorIndex(int index);
  int getSelectorIndex(void);
  bool getSelectorValid(void);

  void setColorPickerRGB(int r, int g, int b);
  void setColorPickerRGB(lv_color32_t rgb);
  void setColorPickerKelvin(int kelvin);
  void setColorPickerBrightnessWhite(int brightness);
  void setColorPickerMode(int mode);
  lv_color32_t getColorPickerRGB(void);
  int getColorPickerKelvin(void);
  int getColorPickerBrightnessWhite(void);
  int getColorPickerMode(void);
};