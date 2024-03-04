<?php
	$a=$_GET["val_a"];
	$b=$_GET["val_b"];
	$produit = 0 ;
	echo "<table border=\"1px solid black\">";
		echo "<tr>" ."<td width=\"90px\" height\"25\">" ."valeur a" ."</td>" ."<td width=\"90px\" height\"25\">" ."valeur b" ."</td>" ."<td width=\"90px\" height\"25\">" ." egale" ."</td>" ."<td width=\"90px\" height\"25\">" ."produit ab" ."</td>" ."</tr>";
	echo "</table>";
	for($i = 1 ; $i<=$b ; $i++){
		$produit = $i * $a;
		echo "<table border=\"1px solid black\">";
		if($i%2===0){
		echo "<tr bgcolor=\"red\" id=\"$i\">" ."<td width=\"90px\" height\"25\">" .$i ."</td>" ."<td width=\"90px\" height\"25\">" .$a ."</td>" ."<td width=\"90px\" height\"25\">" ." =" ."</td>" ."<td width=\"90px\" height\"25\">" .$produit ."</td>" ."<td bgcolor=\"white\">" ."<a href=\"Modifier.html\">Modifier</button>" ."</td>" ."<td bgcolor=\"red\">" ."<button>Supprimer</button>" ."</td>" ."</tr>";
		}
		if($i%2===1){
			echo "<tr bgcolor=\"blue\" id=\"$i\">" ."<td width=\"90px\" height\"25\">" .$i ."</td>" ."<td width=\"90px\" height\"25\">" .$a ."</td>" ."<td width=\"90px\" height\"25\">" ." =" ."</td>" ."<td width=\"90px\" height\"25\">" .$produit ."</td>" ."<td bgcolor=\"white\">" ."<a href=\"Modifier.html\">Modifier</a>" ."</td>" ."<td bgcolor=\"red\">" ."<button>Supprimer</button>" ."</td>" ."</tr>";
		}
	}
    function Modifier($ligne){
        
    }
?>
