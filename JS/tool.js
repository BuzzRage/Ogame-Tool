var curr_resources = [];
var prod = [];

function ogame_tool(){
	var continuer = 1;
		
	console.log("------- Ogame Tool Begin -----");
	console.log("Ce programme va vous assister à la production de vos batiments en fonction de vos ressources.");
	console.log("Que voulez-vous faire ?");
	
	var ans = prompt("
	1. Savoir combien de ressources seront produites dans X temps ? \n
	2. Savoir dans combien de temps les ressources requises pour produire un batiments seront acquises ? \n
	");
	
	switch(ans){
		case 1:
			how_much_resources_in_time();
			break;
		case 2:
			break;
		default:
			break;
	}
	
	console.log("------- Ogame Tool End -------");
}

function get_resources(){
	curr_resources = [];
	curr_resources.push(document.getElementById("resources_metal").innerHTML);
	curr_resources.push(document.getElementById("resources_crystal").innerHTML);
	curr_resources.push(document.getElementById("resources_deuterium").innerHTML);
	//curr_resources.push(document.getElementById("resources_darkmatter").innerHTML);
	curr_resources.push(document.getElementById("resources_energy").innerHTML);
}

function get_prod(){
	prod = [];
	
	// Not working
	prod.push(document.getElementById("metal_box").title);
	prod.push(document.getElementById("crystal_box").title);
	prod.push(document.getElementById("deuterium_box").title);
	prod.push(document.getElementById("energy_box").title);
}

function how_much_resources_in_time(){
	var time = prompt("Combien de temps voulez vous évaluez ?");
	time = format_time(time);
	var results = [0,0,0,0];
	for(var i=0;i<4;i++){
		results.push(prod[i]*time + curr_resources[i]);
	}
	});
	
	console.
}

function format_time(t){
	
}