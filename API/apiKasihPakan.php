<?php 
include ("connect.php");

$sql = "SELECT * FROM waktukasihpakan";
$query = mysqli_query($conn, $sql);
while($data = mysqli_fetch_array($query)){
    $item[] = array(
        'jam'=> $data["jam"],
        'menit'=> $data["menit"],
        'detik'=> $data['detik'],
        'lamaPakan'=> $data['lamaPakan'],
        'kecepatan'=> $data['kecepatan']
    );
};
$respond = array(
    "status" => "OK",
    "data" => $item
); 
echo json_encode($respond);
?>