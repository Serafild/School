<?php
    include_once 'lib/Utils.php';
    include_once 'lib/Database_Manager.php';
    $Database = new DatabaseManager('unity');

    $query = "SELECT * FROM unity.token WHERE value ='" . $_GET['token'] . "' AND (expiration > NOW());";    
    $vToken = $Database->FetchDatabase($query);

    if(!empty($vToken)){
        $query = "SELECT user.username, user.score FROM unity.user ORDER BY user.score DESC";
        $vUser = $Database->FetchDatabase($query);

        if(isset($_GET['token']) && isset($_GET['username']) && isset($_GET['password'])){
            $password = md5($_GET['password']);

            $query = "SELECT * FROM unity.user WHERE username='". $_GET['username'] . "' AND password='". $password ."';";
            $vUser = $Database->FetchDatabase($query);
            if(!empty($vUser)){
                print("User exist");
                die;
            }
            print("User doesn't exist");
            die;
        }
        print("Missing information");
        die;
    }
    print("Token Expired");
?>