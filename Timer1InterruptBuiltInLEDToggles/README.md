<h3>
  Hardware yang digunakan:
  <h5>
    - Arduino Uno R3
    <br>
    - Kabel USB A to B
  </h5>

  <br>
  <br>
  Hampir sama dengan kode Timer0InterruptBuiltInLEDToggles, ini merupakan eksperimen interrupt Timer 1 ATmega328P yang digunakan untuk men-toggle led built-in pada Arduino Uno. Perbedaannya hanya terdapat pada jumlah bit register counternya. Saat dijalankan pada mode normal, Timer 1 akan bekerja seperti counter, nilai TCNT1 (16 bit) akan bertambah setiap sinyal clock. Ketika overflow, maka bit TOV1 pada TIFR1 akan bernilai 1, yang jika kita mengaktifkan TIEO1 pada TIMSK1, maka interrupt akan aktif.
  
  <br>
  <br>
  Dengan preskalar 1/1024, overflow pada TCNT1 akan terjadi setiap 4.194304 detik. Pada program ini, setiap kali overflow terjadi, built-in LED pada Arduino Uno akan berubah state (toggling). Kita dapat mengatur periode toggle yang lebih lama atau lebih cepat dengan menambahkan kondisional seperti pada program Timer0InterruptBuiltInLEDToggles.
