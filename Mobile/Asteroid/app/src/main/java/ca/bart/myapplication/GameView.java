package ca.bart.myapplication;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.text.LoginFilter;
import android.util.AttributeSet;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;

import java.util.Iterator;
import java.util.LinkedList;

public class GameView extends View implements Constants{

    public static final String TAG = "GameView";

    private LinkedList<GameObject> gameObjects = new LinkedList<>();

    private int cx, cy;
    private float scale;
    private float diagonal;
    private float spawnInterval;
    private float timeSinceLastSpawn;
    private Asteroid allAsteroid[] = new Asteroid[30];
    private Ship ship = new Ship(allAsteroid);
    private int nextAsteroid;

    public GameView(Context context) {
        this(context, null);
    }

    public GameView(Context context, AttributeSet attrs) {
        super(context, attrs);
        spawnInterval = .5f;
        timeSinceLastSpawn = spawnInterval;
        nextAsteroid = 0;
        for(int i = 0; i < allAsteroid.length;i++){
            allAsteroid[i] = new Asteroid();
        }
        gameObjects.add(ship);
    }

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {

        cx = w / 2;
        cy = h / 2;
        float min = Math.min(cx, cy);
        float max = Math.max(cx, cy);
        scale = min / 100.0f;

        diagonal = max / min;
    }

    @Override
    protected void onDraw(Canvas canvas) {

        canvas.translate(cx, cy);
        canvas.scale(scale, -scale);

        for (GameObject gameObject : gameObjects) {
            gameObject.onDraw(canvas);
        }
    }

    public void update() {
        for (GameObject gameObject : gameObjects) {
            gameObject.update();
        }

        timeSinceLastSpawn += DELTA_TIME;

        // Spawn a new asteroid
        if (timeSinceLastSpawn > spawnInterval){
            timeSinceLastSpawn -= spawnInterval;

            //Look for a new asteroid to spawn
            while (allAsteroid[nextAsteroid].active){
                nextAsteroid++;
                if (nextAsteroid == allAsteroid.length){
                    nextAsteroid = 0;
                }
            }
            // Spawn it
            allAsteroid[nextAsteroid].Activate(diagonal);
            gameObjects.add(allAsteroid[nextAsteroid]);
        }

        // Remove useless asteroid
        for (Asteroid asteroid: allAsteroid) {
            if(asteroid.toRemove()){
                gameObjects.remove(asteroid);
            }
        }
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {

        switch (event.getActionMasked()){
            case MotionEvent.ACTION_DOWN:
            case MotionEvent.ACTION_POINTER_DOWN:
                Laser myLaser = new Laser();
                ship.Fire(myLaser);
                gameObjects.add(myLaser);
        }

        for (Iterator<GameObject> i = gameObjects.descendingIterator(); i.hasNext(); ) {
            GameObject gameObject = i.next();
            if (gameObject.onTouchEvent(event)) {
                return true;
            }
        }
        return super.onTouchEvent(event);
    }
}
