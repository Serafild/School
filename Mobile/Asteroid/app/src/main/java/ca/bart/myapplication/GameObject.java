package ca.bart.myapplication;

import android.graphics.Canvas;
import android.view.MotionEvent;

/**
 * Created by guifra on 2017-10-17.
 * Modified by MarcAntoine on 2017-30-17
 */

public interface GameObject {
    void onDraw(Canvas canvas);
    void update();
    boolean onTouchEvent(MotionEvent event);
    boolean toRemove();
}
