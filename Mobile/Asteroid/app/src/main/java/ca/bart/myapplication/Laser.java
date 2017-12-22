package ca.bart.myapplication;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.Log;
import android.view.MotionEvent;

/**
 * Created by 1630092 on 02/11/2017.
 */

public class Laser implements GameObject, Constants {

    public static final String TAG = "Laser";

    public float rotation;
    private Paint paint;
    private float lifeTime;
    private float timeSinceCreation;
    private boolean skip;


    public Laser(){
        paint = new Paint();
        paint.setColor(Color.BLACK);
        paint.setStrokeWidth(2);
        //rotation = Ship.rotation;
        lifeTime = .3f;
        timeSinceCreation = 0;
        Log.e(TAG, "Laser:" + rotation);
        skip = false;
    }

    @Override
    public void onDraw(Canvas canvas) {
        if(!(skip)){
            skip = true;
            return;
        }
        if(timeSinceCreation > lifeTime){
            return;
        }
        canvas.save();
        {
            canvas.rotate(rotation);

            canvas.translate(23, 0);

            canvas.drawLine(0, 0, 200, 0, paint);
        }
        canvas.restore();
    }

    @Override
    public void update() {
        timeSinceCreation += DELTA_TIME;
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        return false;
    }

    @Override
    public boolean toRemove() {
        return false;
    }
}
