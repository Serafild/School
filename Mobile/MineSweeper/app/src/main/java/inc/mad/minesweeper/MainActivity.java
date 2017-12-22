package inc.mad.minesweeper;

import android.app.Activity;
import android.nfc.Tag;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.GridLayout;
import android.widget.TextView;

import java.util.Random;

public class MainActivity extends Activity {

    public static final String TAG = "MainActivity";

    public boolean revealed[] = new boolean[100];
    public int under[] = new int[100];

    public boolean gameOver;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                final int x = i;
                final int y = j;
                getButtonByCoordinates(i, j).setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        onCellClicked(x, y);
                    }
                });
            }
        }

        final TextView mineLeft = (TextView) findViewById(R.id.MineLeft);

        Button NewGameButton = findViewById(R.id.NewGame);

        NewGameButton.setOnClickListener(new View.OnClickListener() {
            @Override
             public void onClick(View view) {
                 onCreate(null);
             }
         });

        NewGame();
    }

    public void NewGame()
    {
        gameOver = false;

        for (int i = 0; i <= 99; ++i) {
            revealed[i] = false;
            under[i] = 0;
        }

        int minePlaced = 0;

        while(minePlaced < 10){
            Random r = new Random();
            int position = r.nextInt(99);
            under[position] = 9;
            minePlaced = MineAmount();
        }

        //TODO
        //1- Simplify if statement
        //2- Fix the "Across the screen" bug
        for (int i = 0; i <= 99; ++i){
            //TL
            if(CheckForMine(i - 11) && under[i] != 9){
                if(!(i <= 9) || i % 10 == 0)
                    under[i]++;
            }
            //T
            if(CheckForMine(i - 10) && under[i] != 9){
                if(!(i <= 9))
                    under[i]++;
            }
            //TR
            if(CheckForMine(i - 9) && under[i] != 9){
                if(!(i <= 9 /*|| i % 9 == 0*/))
                    under[i]++;
            }
            //L
            if(CheckForMine(i - 1) && under[i] != 9){
                if(!(i % 10 == 0))
                    under[i]++;
            }
            //R
            if(CheckForMine(i + 1) && under[i] != 9){
                if(!(i % 9 == 0))
                    under[i]++;
            }
            //BL
            if(CheckForMine(i + 9) && under[i] != 9){
                if(!(i % 10 == 0 || i > 90))
                    under[i]++;
            }
            //B
            if(CheckForMine(i + 10) && under[i] != 9){
                if(!(i > 90))
                    under[i]++;
            }
            //BR
            if(CheckForMine(i + 11) && under[i] != 9){
                if(!(i > 90 || i % 9 == 0))
                    under[i]++;
            }
        }
    }

    public boolean CheckForMine(int pos){
        if(pos < 0 || pos > 99){
            return false;
        }
        else if(under[pos] == 9){
            return true;
        }
        return false;
    }

    public int MineAmount(){
        int amount = 0;
        for (int i = 0; i <= 99; ++i) {
            if(under[i] == 9){
                amount ++;
            }
        }
        return amount;
    }

    public Button getButtonByCoordinates(int x, int y) {
        GridLayout gridLayout = findViewById(R.id.Grid);
        return (Button) gridLayout.getChildAt(y * 10 + x);
    }

    public void onCellClicked(int x, int y) {
        if(gameOver)
            return;

        if(x < 0 || x > 9 || y < 0 || y > 9)
            return;

        //Log.e(TAG, "cell clicked " + x + " " + y);
        //Log.e(TAG, String.valueOf(under[x + y * 10]));
        if(!(revealed[x + y * 10])){
            revealed[x + y * 10] = true;
            switch (under[x + y * 10]){
                case 0:
                    getButtonByCoordinates(x,y).setBackgroundResource(R.drawable.vide);
                    RevealSurrounding(x,y);
                    break;
                case 1:
                    getButtonByCoordinates(x,y).setBackgroundResource(R.drawable.tile_1);
                    break;
                case 2:
                    getButtonByCoordinates(x,y).setBackgroundResource(R.drawable.tile_2);
                    break;
                case 3:
                    getButtonByCoordinates(x,y).setBackgroundResource(R.drawable.tile_3);
                    break;
                case 4:
                    getButtonByCoordinates(x,y).setBackgroundResource(R.drawable.tile_4);
                    break;
                case 5:
                    getButtonByCoordinates(x,y).setBackgroundResource(R.drawable.tile_5);
                    break;
                case 6:
                    getButtonByCoordinates(x,y).setBackgroundResource(R.drawable.tile_6);
                    break;
                case 7:
                    getButtonByCoordinates(x,y).setBackgroundResource(R.drawable.tile_7);
                    break;
                case 8:
                    getButtonByCoordinates(x,y).setBackgroundResource(R.drawable.tile_8);
                    break;
                case 9:
                    getButtonByCoordinates(x,y).setBackgroundResource(R.drawable.mine);
                    gameOver = true;
                    break;
            }
        }
    }

    public void RevealSurrounding(int x, int y){
        onCellClicked(x + 1, y - 1); //BR
        onCellClicked(x + 1 ,y);     //R
        onCellClicked(x + 1, y + 1); //TR
        onCellClicked(x, y + 1);     //T
        onCellClicked(x, y - 1);     //B
        onCellClicked(x - 1, y - 1); //BL
        onCellClicked(x - 1, y);     //L
        onCellClicked(x - 1, y + 1); //TL
        return;
    }

    public void ResetGame(){
        for (int i = 1; i <= 100; ++i) {
            getButtonByCoordinates(i % 11, i / 10).setBackgroundResource(R.drawable.inactif);
        }
    }
}
