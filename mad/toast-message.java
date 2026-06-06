/*
--- activity_main.xml ---
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 android:orientation="vertical" >

 <Button
 android:id="@+id/btnShow"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:text="Show Toast"
 android:layout_marginTop="200dp" android:layout_marginLeft="140dp"/>

</LinearLayout>
*/

import android.view.View;
import android.widget.Button;
import android.widget.Toast;

Button btn = (Button)findViewById(R.id.btShow);
btn.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View v) {
 Toast.makeText(MainActivity.this, "TOAST MESSAGE: You Clicked on Button..", Toast.LENGTH_SHORT).show();
 }
});
