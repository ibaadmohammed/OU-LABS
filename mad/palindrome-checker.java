/*
--- activity_main.xml ---
<EditText
 android:id="@+id/string"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:ems="10"
 android:inputType="textPersonName"
 android:minHeight="48dp"
 android:hint="Enter the String"
 app:layout_constraintBottom_toBottomOf="parent"
 app:layout_constraintEnd_toEndOf="parent"
 app:layout_constraintHorizontal_bias="0.497"
 app:layout_constraintStart_toStartOf="parent"
 app:layout_constraintTop_toTopOf="parent"
 app:layout_constraintVertical_bias="0.192" />

 <Button
 android:id="@+id/button"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:text="Check Palindrome"
 app:layout_constraintStart_toStartOf="@+id/string"
 app:layout_constraintEnd_toEndOf="@+id/string"
 app:layout_constraintTop_toBottomOf="@+id/string"
 android:layout_marginTop="30dp"/>

 <TextView
 android:id="@+id/textView"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:textSize="14sp"
 app:layout_constraintStart_toStartOf="@+id/button"
 app:layout_constraintEnd_toEndOf="@+id/button"
 app:layout_constraintTop_toBottomOf="@+id/button"
 android:layout_marginTop="30dp"/>
*/

import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

EditText string;
TextView result;
Button button;

string = findViewById(R.id.string);
result = findViewById(R.id.textView);
button = findViewById(R.id.button);

button.setOnClickListener(view -> {
 String stringValue = string.getText().toString();
 checkPalindrome(stringValue);
});

// outside oncreate() method a checkpalindrome() method is created
private void checkPalindrome(String stringValue) {
 String reversed = new StringBuilder(stringValue).reverse().toString();
 if(stringValue.equals(reversed))
 {
 result.setText("Palindrome");
 }
 else
 {
 result.setText("Not Palindrome");
 }
}
