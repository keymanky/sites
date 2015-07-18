function refresca()
{
	location.reload(true);
}
function show(bloq) {
    obj = document.getElementById(bloq);
    obj.style.display = (obj.style.display == 'none') ? 'block' : 'none';
}