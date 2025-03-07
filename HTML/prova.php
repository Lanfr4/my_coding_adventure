<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Recupera i dati dal modulo
    $nome = $_POST['fname'];
    $cognome = $_POST['lname'];

    // Stampa i dati
    echo "Nome: " . htmlspecialchars($nome) . "<br>";
    echo "Cognome: " . htmlspecialchars($cognome) . "<br>";
}
?>