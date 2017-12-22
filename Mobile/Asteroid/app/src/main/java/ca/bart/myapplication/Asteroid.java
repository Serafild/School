package ca.bart.myapplication;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.Log;
import android.view.MotionEvent;
import java.util.Random;

/**
 * Created by Me on 31/10/2017.
 */

public class Asteroid implements GameObject, Constants{

    public static final String TAG = "Asteroid";

    private Paint paint = new Paint();
    private Random rand = new Random();
    private int nbSide;
    public int angle;
    private float distanceToEarth;
    private float rotation;
    private float rotationSide;
    private float distanceToSpawn;
    public boolean active;
    public boolean removeMe;

    public Asteroid(){

        active = false;
        removeMe = false;
    }

    public void Activate(float diagonal){

        distanceToSpawn = (float)Math.sqrt(Math.pow(100 * diagonal ,2) + 100 * 100);

        switch (rand.nextInt(6)){
            case (0):
                paint.setColor(Color.BLUE);
                break;
            case (1):
                paint.setColor(Color.RED);
                break;
            case (2):
                paint.setColor(Color.YELLOW);
                break;
            case (3):
                paint.setColor(Color.GREEN);
                break;
            case (4):
                paint.setColor(Color.BLACK);
                break;
            case(5):
                paint.setColor(Color.argb(255,255,165,0));
                break;
            default:
                paint.setColor(Color.BLUE);
                Log.e(TAG, "Asteroid: This should not have been called");
                break;
        }
        nbSide = rand.nextInt(4) + 5;
        angle = rand.nextInt(360);
        distanceToEarth = distanceToSpawn;
        active = true;
        removeMe = false;
        rotation = 0;

        if(rand.nextBoolean()) {
            rotationSide = 1;
        }
        else {
            rotationSide = -1;
        }
    }

    public void Shoot(float _angle){
        _angle -= 90;
        if(_angle < 0){
            _angle += 360;
        }
        if(_angle - angle < 5 && _angle - angle > -5){
            Deactivate();
        }
    }

    @Override
    public boolean toRemove(){
        return removeMe;
    }

    @Override
    public void onDraw(Canvas canvas) {
        if(active) {
            canvas.save();
            {
                paint.setStyle(Paint.Style.STROKE);
                paint.setStrokeWidth(1.5f);

                canvas.rotate(angle);
                canvas.translate(0, distanceToEarth);
                canvas.rotate(rotation);

                Helper.drawPolygon(canvas, paint, 5, nbSide);
            }
            canvas.restore();
        }
    }

    public void Deactivate(){
        removeMe = true;
        active = false;
    }

    @Override
    public void update(){
        if(active) {
            distanceToEarth -= DELTA_TIME * 50;
            if (distanceToEarth <= 0) {
                Deactivate();
            }
            rotation += (DELTA_TIME * (360 * 2)) * rotationSide;
        }
    }

    @Override
    public boolean onTouchEvent(MotionEvent event){
        return false;
    }
}
