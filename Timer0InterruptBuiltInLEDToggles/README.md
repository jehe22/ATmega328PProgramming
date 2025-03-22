<h3>
  Hardware yang digunakan:
  <h5>
    - Arduino Uno R3
    <br>
    - Kabel USB A to B
  </h5>

  <br>
  <br>
  Ini merupakan eksperimen interrupt Timer 0 ATmega328P yang digunakan untuk men-toggle led built-in pada Arduino Uno. Saat dijalankan pada mode normal, Timer 0 akan bekerja seperti counter, nilai TCNT0 akan bertambah setiap sinyal clock. Ketika overflow, maka bit TOV0 pada TIFR0 akan di-set yang jika kita mengaktifkan TIEO0 pada TIMSK0, maka interrupt akan aktif.
  
  <br>
  <br>
  Karena sekali overflow hanya beberapa milidetik saja (dalam hal ini 0.064 milidetik), kita dapat menghitung jumlah overflownya untuk menghitung waktu yang lebih panjang. Dengan if else branch, kita dapat menentukan waktu untuk men-toggle led built in berdasarkan perhitungan overflow dan sebuah variabel pembantu. Program ini akan mengedipkan built-in LED pada Arduino Uno setiap sekitar 4.194304 detik.
