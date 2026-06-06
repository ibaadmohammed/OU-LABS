/*
--- activity_main.xml ---
<Button
 android:id="@+id/selectImages"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:text="Select Images"
 app:layout_constraintBottom_toBottomOf="parent"
 app:layout_constraintEnd_toEndOf="parent"
 app:layout_constraintStart_toStartOf="parent"
 app:layout_constraintTop_toTopOf="parent"
 app:layout_constraintVertical_bias="0.361" />

 <ImageView
 android:id="@+id/imageView"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 app:layout_constraintStart_toStartOf="@+id/selectImages"
 app:layout_constraintTop_toBottomOf="@+id/selectImages"
 app:layout_constraintEnd_toEndOf="@+id/selectImages"
 android:layout_marginTop="50dp"
 tools:srcCompat="@tools:sample/avatars" />
*/

import androidx.activity.result.ActivityResultLauncher;
import android.widget.Button;
import android.widget.ImageView;

Button selectImages;
ActivityResultLauncher<String> chooseImage;
ImageView imageView;

selectImages = findViewById(R.id.selectImages);
imageView = findViewById(R.id.imageView);
chooseImage = registerForActivityResult(new ActivityResultContracts.GetContent(), result -> imageView.setImageURI(result));
selectImages.setOnClickListener(v -> {
 chooseImage.launch("image/*");
});
