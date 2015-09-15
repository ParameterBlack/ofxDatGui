/*
    Copyright (C) 2015 Stephen Braitsch [http://braitsch.io]

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma once
#include "ofxDatGuiGroups.h"
#include "ofxDatGuiControls.h"

class ofxDatGui : public ofxDatGuiInteractiveObject
{
    
    public:
    
        ofxDatGui(int x, int y);
        ofxDatGui(ofxDatGuiAnchor anchor = ofxDatGuiAnchor::TOP_LEFT);
    
        void draw();
        void update();
    
        void setWidth(int width);
        void setOrigin(int x, int y);
        void setVisible(bool visible);
        void setEnabled(bool enabled);
        void setOpacity(float opacity);
        void setAutoDraw(bool autodraw);
        void setAlignment(ofxDatGuiAlignment align);
    
        int getWidth();
        int getHeight();
        ofPoint getPosition();
    
        ofxDatGuiHeader* addHeader(string label = "");
        ofxDatGuiFooter* addFooter();
        ofxDatGuiLabel* addLabel(string label);
        ofxDatGuiButton* addButton(string label);
        ofxDatGuiToggle* addToggle(string label, bool state);
        ofxDatGuiSlider* addSlider(string label, float min, float max);
        ofxDatGuiSlider* addSlider(string label, float min, float max, float val);
        ofxDatGuiTextInput* addTextInput(string label, string value = "");
        ofxDatGuiDropdown* addDropdown(vector<string> options);
        ofxDatGuiFPS* addFPS();
        ofxDatGuiBreak* addBreak(int height = 0);
        ofxDatGui2dPad* add2dPad(string label);
        ofxDatGui2dPad* add2dPad(string label, ofRectangle bounds);
        ofxDatGuiColorPicker* addColorPicker(string label, ofColor color = ofColor::black);
        ofxDatGuiMatrix* addMatrix(string label, int numButtons, bool showLabels = false);
        ofxDatGuiFolder* addFolder(string label, ofColor color = ofxDatGuiColor::LABEL);
    
    // experimental //
        ofxDatGuiButton* getButton(string key);
        ofxDatGuiSlider* getSlider(string key);
        ofxDatGui2dPad* get2dPad(string key);
        ofxDatGuiDropdown* getDropdown(string key);
        ofxDatGuiTextInput* getTextInput(string key);
        ofxDatGuiColorPicker* getColorPicker(string key);
        ofxDatGuiMatrix* getMatrix(string key);
    
    private:
    
        int mWidth;
        int mHeight;
        int mHeightMinimum;
        int mRowSpacing;
        float mAlpha;
        bool mVisible;
        bool mEnabled;
        bool mExpanded;
        bool mAlphaChanged;
        bool mWidthChanged;
        bool mAlignmentChanged;
        ofxDatGuiAlignment mAlignment;
    
        bool mousePressed;
        ofPoint mouse;
        ofPoint mPosition;
        ofxDatGuiFont* mFont;
        ofxDatGuiAnchor mAnchor;
        ofxDatGuiItem* activeHover;
        ofxDatGuiItem* activeFocus;
        ofxDatGuiHeader* mGuiHeader;
        ofxDatGuiFooter* mGuiFooter;
        vector<ofxDatGuiItem*> items;
        vector<ofxDatGuiItem*> trash;
    
        void init();
        void layoutGui();
        void anchorGui();
        void expandGui();
        void collapseGui();
        void moveGui(ofPoint pt);
        void attachItem(ofxDatGuiItem* item);
        void adjustHeight(int index);
        void setGuiAlpha();
        void setGuiWidth();
        void setGuiAlignment();
    
        void onDraw(ofEventArgs &e);
        void onUpdate(ofEventArgs &e);
        
        bool isMouseOverRow(ofxDatGuiItem* row);
        bool isMouseOverGui();
        void onKeyPressed(ofKeyEventArgs &e);
        void onMousePressed(ofMouseEventArgs &e);
        void onMouseReleased(ofMouseEventArgs &e);
        void onWindowResized(ofResizeEventArgs &e);
    
        ofxDatGuiItem* getComponent(string key);
        void onInternalEventCallback(ofxDatGuiInternalEvent e);
        void onButtonEventCallback(ofxDatGuiButtonEvent e);
        void onSliderEventCallback(ofxDatGuiSliderEvent e);
        void onTextInputEventCallback(ofxDatGuiTextInputEvent e);
        void onDropdownEventCallback(ofxDatGuiDropdownEvent e);
        void on2dPadEventCallback(ofxDatGui2dPadEvent e);
        void onColorPickerEventCallback(ofxDatGuiColorPickerEvent e);
        void onMatrixEventCallback(ofxDatGuiMatrixEvent e);

};
