<?php
    include "connect.php";
    $pakan = isset($_POST['pakan']) ? $_POST["pakan"]:"";

    $sql = "INSERT INTO kondisi_pakan (pakan) VALUES ('".$pakan."');";
    $query = mysqli_query($conn, $sql);
    if(!$query){
        echo("Gagal Insert");
    }else{
        echo("Berhasil Insert");
    }
?>