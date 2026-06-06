/*
--- activity_main.xml ---
<RelativeLayout
 xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:tools="http://schemas.android.com/tools"
 android:id="@+id/idRLContainer"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 android:orientation="vertical"
 tools:context=".MainActivity">

 <TextView
 android:id="@+id/idTVStatus"
 android:layout_width="match_parent"
 android:layout_height="wrap_content"
 android:layout_above="@id/idBtnToggle"
 android:layout_centerInParent="true"
 android:layout_margin="20dp"
 android:gravity="center"
 android:padding="10dp"
 android:text="Status"
 android:textAlignment="center"
 android:textColor="@color/black"
 android:textSize="20sp"
 android:textStyle="bold" />

 <ToggleButton
 android:id="@+id/idBtnToggle"
 android:layout_width="match_parent"
 android:layout_height="65dp"
 android:layout_centerInParent="true"
 android:layout_margin="20dp"
 android:padding="10dp"
 android:textAllCaps="true"
 android:textColor="@color/black"
 android:textOff="Off"
 android:textOn="On" />

</RelativeLayout>
*/

import android.view.View;
import android.widget.TextView;
import android.widget.ToggleButton;

private ToggleButton toggleBtn;
private TextView statusTV;

toggleBtn = findViewById(R.id.idBtnToggle);
statusTV = findViewById(R.id.idTVStatus);

if (toggleBtn.isChecked()) {
 statusTV.setText("Toggle Button is On");
} else {
 statusTV.setText("Toggle Button is Off");
}

toggleBtn.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View v) {
 if (toggleBtn.isChecked()) {
 statusTV.setText("Toggle Button is On");
 } else {
 statusTV.setText("Toggle Button is Off");
 }
 }
});
