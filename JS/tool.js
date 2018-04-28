var curr_resources = [];

function ogame_tool(){
	var continuer = 1;
	
	curr_resources.push(document.getElementById("resources_metal").innerHTML);
	curr_resources.push(document.getElementById("resources_crystal").innerHTML);
	curr_resources.push(document.getElementById("resources_deuterium").innerHTML);
	curr_resources.push(document.getElementById("resources_darkmatter").innerHTML);
	curr_resources.push(document.getElementById("resources_energy").innerHTML);
	
	
	console.log("------- Ogame Tool Begin -----");
	console.log("Ce programme va vous assister à la production de vos batiments en fonction de vos ressources.");
	console.log("Que voulez-vous faire ?");
	console.log("------- Ogame Tool End -------");
}