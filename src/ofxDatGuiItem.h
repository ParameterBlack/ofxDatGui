//
//  ofxDatGuiItem.h
//  ofxDatGui
//
//  Created by Stephen Braitsch on 8/17/15.
//
//

#pragma once
#include "ofxDatGuiSettings.h"

class ofxDatGuiItem
{
    public:
    
        ofxDatGuiItem(int id);
        ofxDatGuiItem(int id, string label, bool centerLabel = false) : ofxDatGuiItem(id)
        {
            mLabel = label;
        }
        
        virtual void draw() = 0;
        virtual bool hitTest(ofPoint m) = 0;
    
        virtual void onMouseEnter(ofPoint m);
        virtual void onMousePress(ofPoint m) = 0;
        virtual void onMouseDrag(ofPoint m);
        virtual void onMouseLeave(ofPoint m);
        virtual void onMouseRelease(ofPoint m);

    // this typedef is also used in ofxDatGui.h //
        typedef std::function<void(ofxDatGuiEvent)> onChangeEventCallback;
        onChangeEventCallback changeEventCallback;
        
        template<typename T, typename args, class ListenerClass>
        void onGuiEvent(T* owner, void (ListenerClass::*listenerMethod)(args))
        {
            using namespace std::placeholders;
            changeEventCallback = std::bind(listenerMethod, owner, _1);
        }

        static const uint16_t rowWidth;
        static const uint16_t rowHeight;
        static const uint16_t rowPadding;
        static const uint16_t rowSpacing;

    protected:
        int x;
        int y;
        int mId;
        string mLabel;
        bool mMouseOver;
        static ofPoint labelPosition;
    
        void drawBkgd(ofColor bkgd_color = ofxDatGuiColor::ROW_BKGD);
        void drawLabel(ofColor label_color = ofxDatGuiColor::LABEL);
    
        static const uint16_t labelX;
        static const uint16_t labelWidth;
        static const uint16_t sliderX;
        static const uint16_t sliderWidth;
        static const uint16_t sliderLabelX;
        static const uint16_t sliderLabelWidth;

};

