/*
--- activity_main.xml ---
<Button
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:text="submit"
 android:id="@+id/button"
 app:layout_constraintBottom_toBottomOf="parent"
 app:layout_constraintLeft_toLeftOf="parent"
 app:layout_constraintRight_toRightOf="parent"
 app:layout_constraintTop_toTopOf="parent"
 app:layout_constraintVertical_bias="0.615" />

 <RatingBar
 android:id="@+id/ratingBar"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_marginLeft="72dp"
 android:layout_marginTop="60dp"
 app:layout_constraintStart_toStartOf="parent"
 app:layout_constraintTop_toTopOf="parent" />
*/

import android.view.View;
import android.widget.Button;
import android.widget.RatingBar;
import android.widget.Toast;

RatingBar ratingbar;
Button button;

// Add this below method calling in onCreate() method but method definition is in
// outside onCreate() and inside Mainactivity class
addListenerOnButtonClick();

public void addListenerOnButtonClick() {
 ratingbar = (RatingBar) findViewById(R.id.ratingBar);
 button = (Button) findViewById(R.id.button);
 button.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View arg0) {
 String rating = String.valueOf(ratingbar.getRating());
 Toast.makeText(getApplicationContext(), rating, Toast.LENGTH_LONG).show();
 }
 });
}
