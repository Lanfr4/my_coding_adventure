<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Recupera i dati dal modulo
    $nome = $_REQUEST['fname'];
    $cognome = $_REQUEST['lname'];

    // Stampa i dati
     echo "Nome: " . $nome . "<br>";
    //echo "Cognome: " . htmlspecialchars($cognome) . "<br>";
}
?>