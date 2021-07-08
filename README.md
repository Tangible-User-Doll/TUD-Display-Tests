<h1>Test-Display</h1>
Ein Beispiel-Code, in dem eine Nachricht auf dem OLED Bildschirm angezeigt wird, welche abhängig davon ist, wie oft der Touch-Sensor gedrückt wird.

<h2>Anschließen des Displays:</h2>

![oled](https://user-images.githubusercontent.com/38287998/124848142-87225b00-df9c-11eb-9615-59091abfb918.jpg)

<ul>
  <li>grau: GND > GND</li>
  <li>magenta: Vin > 5V</li>
  <li>blau: nichts (falsch im Foto, idk why)</li>
  <li>grün: nichts</li>
  <li>gelb: RST > 4</li>
  <li>orange: nichts</li>
  <li>rot: Clk > A5</li>
  <li>braun: Data > A4</li>
</ul>

Zusätzlich sollte der Touch-Sensor mit Pin 7 verbunden werden.

<h2>Ablauf des Programms: </h2>

Wenn der Touch Sensor berührt wird, wird ein String (message) von rechts nach links über den Bildschirm gescrollt. Je nachdem, wie oft der Sensor innerhalb einer halben Sekunde berührt wird, wird ein anderer Absender oben rechts in der Ecke angezeigt. 

