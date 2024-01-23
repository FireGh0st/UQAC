package uqac.dim.nitflex;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item){

        int itemId = item.getItemId();
        if (itemId == R.id.item_menu1) {
            Log.i("DIM", "Item 1");
            return true;
        } else if (itemId == R.id.item_menu2) {
            Log.i("DIM", "Very useful item 2");
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
    public void click(View v){
        Log.i("DIM", "un log");
        //TextView texteHello = (TextView)findViewById(R.id.texte_hello);
       // ((Button)v).setText(texteHello.getText());
    }

}