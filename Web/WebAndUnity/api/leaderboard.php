<?php
    include_once 'lib/Utils.php';
    include_once 'lib/Database_Manager.php';

    $database = new DatabaseManager('unity');

    $query = "SELECT * FROM unity.token WHERE value ='" . $_GET['token'] . "' AND (expiration > NOW());";
    $vToken = $database->FetchDatabase($query);
    
    if(!empty($vToken)){
        $query = "SELECT user.username, user.score FROM unity.user ORDER BY user.score DESC";
        $vUser = $database->FetchDatabase($query);
    
        foreach ($vUser as $User){
                print($User['username']);
                print(' ');
                print($User['score']);
                print('-');
        }
        die;
    }
    print("Token expired");
?>