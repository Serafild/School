package ca.bart.myapplication;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.util.Log;
import android.view.MotionEvent;

/**
 * Created by marca on 31/10/2017.
 */

public class Ship implements GameObject {

    private static final String TAG = "Ship";

    private Paint paint;
    private Paint laserPaint;
    private int shipSize;
    public float rotation;

    private int touchId = -1;
    private Matrix matrix = new Matrix();
    private float[] points = new float[2];
    private boolean fire;
    private Laser myLaser;
    private Asteroid[] allAsteroid;


    public Ship(Asteroid[] _allAsteroid){
        paint = new Paint();
        paint.setColor(Color.RED);
        paint.setStrokeWidth(1);

        laserPaint = new Paint();
        laserPaint.setColor(Color.BLACK);
        laserPaint.setStrokeWidth(2);

        allAsteroid = _allAsteroid;

        shipSize = 8;
        rotation = 0;
        fire = false;
    }

    @Override
    public void onDraw(Canvas canvas) {
        canvas.save();
        {
            canvas.getMatrix().invert(matrix);
            canvas.rotate(rotation);

            //Have the back of the ship be the 0,0
            canvas.translate(shipSize,0);

            //Move it far enough
            canvas.translate(15,0);

            Helper.drawTriangle(canvas, paint, shipSize, 60, true);
        }
        canvas.restore();
    }

    public void Fire(Laser laser){
        fire = true;
        myLaser = laser;
    }

    @Override
    public void update() {
        if(fire){
            myLaser.rotation = rotation;

            for (Asteroid asteroid: allAsteroid
                 ) {
                if(asteroid.active){
                    asteroid.Shoot(rotation);
                }
            }
            fire = false;
        }
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {

        int index = event.getActionIndex();
        int id = event.getPointerId(index);

        switch (event.getActionMasked()) {
            case MotionEvent.ACTION_DOWN:
            case MotionEvent.ACTION_POINTER_DOWN:

                //fire = true;
                if (touchId != -1) {
                    return false;
                }
                touchId = id;

            case MotionEvent.ACTION_MOVE:

                if (touchId == id) {

                    points[0] = event.getX(index);
                    points[1] = event.getY(index);
                    matrix.mapPoints(points);

                    rotation = (float)Math.toDegrees(Math.atan2(points[1], points[0]));
                    return true;
                }
                break;

            case MotionEvent.ACTION_POINTER_UP:
            case MotionEvent.ACTION_UP:
            case MotionEvent.ACTION_CANCEL:

                if (touchId == id) {
                    touchId = -1;
                    return true;
                }
                break;
        }
        return false;
    }

    @Override
    public boolean toRemove() {
        return false;
    }
}
