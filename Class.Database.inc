<?php

class Database{
    private $connection;
    private static $instance;


    public function __construct(){

        $this->connection = mysqli_connect('localhost','root','root','oop');
        if(mysqli_connect_error()){
            trigger_error("unable to connect".mysqli_connect_error(),E_USER_ERROR);
        }
    }

    public static function getInstance(){
        if(!self::$instance){
            self::$instance = new self();
        }
        return self::$instance;
    }

    public function getConnection(){
        return $this->connection;
    }

    private function __clone(){}

}