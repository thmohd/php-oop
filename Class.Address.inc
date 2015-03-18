<?php


/**
 * This is just a sample class represent the address
 * Class Address
 */
class Address{

    public $name;
    public $street;
    protected $ssn;


    /**
     * @return string
     */
    public function __toString(){
        return $this->dispaly();
    }

    /**
     * @param array $data
     */
    public function __construct($data = array()){

        if(!is_array($data)){
            return;
        }
        else{
            foreach($data as $key=>$value){
                $this->$key = $value;
            }
        }
    }

    /**
     * Simple method to display the address
     * @return string
     */
    public function dispaly(){


        return "Name: {$this->name} - {$this->street} - {$this->ssn}";
    }

    /**
     * Magic setter for the class properties
     * @param $name
     * @param $value
     * @return null
     */
    public function __set($name,$value){

        if(property_exists($this,$name)){
            $this->$name = $value;
        }
        else{
            trigger_error("this is not properties");
            return null;
        }
    }

    /**
     * Sample metod to store the name in the database , Assuming table name is test
     * @param null $name
     */

    public function saveNametoDB($name = null){

        if(!is_null($name)){

            $db = Database::getInstance();
            $mysql = $db->getConnection();
            $sql_query =" INSERT INTO test.address ('name')  VALUES ('{$name}')";
            $mysql->query($sql_query);

        }

    }

    /**
     * Retreive all address from DB
     * @return bool|mysqli_result
     */
    public function displayFromDB(){
        $db = Database::getInstance();
        $mysql = $db->getConnection();
        $result = $mysql->query("SELECT * FROM test");

        return $result;
    }

}