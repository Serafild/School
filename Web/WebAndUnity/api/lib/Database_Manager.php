<?php
class DatabaseManager {
	private $connection;
	private $id; 
	private $schema;

	public function __construct($str = "") {
		$this->schema = $str;
		$servername = "localhost";
		$username = "root";
		$password = "";
		$this->connection = new mysqli($servername, $username, $password);
	}
	/**
	 *
	 * @param $query
	 */
	public function FetchDatabase($query) {
		$result = $this->connection->query($query);
		$response = [];
		if($result !== TRUE) {
			if(mysqli_num_rows($result) > 0) {
				while($row = mysqli_fetch_assoc($result)) {
					$response []= $row;
				}
			}
		}

		return $response;
	}
}
?>
 