const DIAMETRE_BALLE = 103; //Diamètre de la balle en pixels, on ajoute 3 pixels
//pour éviter l'apparition des barres de scroll


console.log(deplace_balle);
function deplace_balle() {
    let ma_balle = document.getElementById("balle");
    let pos_x = ma_balle.offsetLeft + 1;
	let pos_y = ma_balle.offsetTop + 1;
// Si on touche le bord bas OU le bord droit de la fenêtre
	if ((pos_y > (window.innerHeight - DIAMETRE_BALLE)) || (pos_x >= (document.body.offsetWidth - DIAMETRE_BALLE))) {
        pos_x = 0;   // La balle revient en haut à gauche de la fenêtre
		pos_y = 0;
		}
	ma_balle.style.left = pos_x + "px";
	ma_balle.style.top = pos_y + "px";
}
console.log("width : " + document.body.offsetWidth + " Height : " + window.innerHeight);
setInterval(deplace_balle,15); // Appel la fonction deplaceBalle toutes les 10 ms

console.log(position_balle)
function position_balle(){
    let position_x = 0;
    let position_y = 0;
    if (position_x < document.body.offsetWidth)
        position_x++;
    if (position_y < window.innerHeight)
        position_y++;
}