<h3>
  Hardware yang digunakan:
  <h5>
    - Arduino Uno R3
    <br>
    - Kabel USB A to B
  </h5>
  
  <br>
  Ini merupakan eksperimen interrupt Timer 2 dan juga interrupt perubahan state pin ATmega328P yang digunakan untuk men-toggle LED built-in pada Arduino Uno. Saat dijalankan pada mode normal, Timer 2 akan bekerja seperti counter, nilai TCNT2 akan bertambah setiap sinyal clock. Ketika overflow, maka bit TOV2 pada TIFR2 akan di-set yang jika kita mengaktifkan TIEO2 pada TIMSK2 maka interrupt service routine akan dijalankan. Interrupt ini akan dihitung jumlahnya.

  <br>
  <br>
  Pin change interrupt diaktifkan dengan mengatur register PCMSKn dan PCICR. Pada kode, bit PCINT4 yang di-set 1 pada register PCMSK0 akan menjadikan pin digital 12 sebagai salah satu pin untuk interrupt. Bit PCIE0 yang bernilai 1 pada register PCICR akan mengaktifkan pin change interrupt pada seluruh pin pada port B. Jika terjadi perubahan state pada pin digital 12 maka interupt service routine akan dijalankan.
  
  <br>
  <br>
  Ketika jumlah interrupt Timer 2 mencapai nilai tertentu, pin digital 12 yang semula LOW akan di-set HIGH. Ini akan mengaktifkan pin change interrupt sehingga pin digital 13 akan di-toggle. Jadi, program ini akan menghitung jumlah Timer 2 interrupt dan jumlah tersebut akan digunakan untuk pin change interrupt yang akan men-toggle pin digital 13. Periode kedipan pin digital 13 (built-in LED) ini akan terjadi sekitar 4.194304 detik.
