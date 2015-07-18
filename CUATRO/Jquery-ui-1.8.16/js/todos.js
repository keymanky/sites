$(document).ready(function(){
	//ToolTip
	$('.tTip').betterTooltip({speed: 150, delay: 300});
	//Formulario
	$("input, textarea, select, button").uniform();
	//Acordeon
	$(".accordion h3:first").addClass("active");
	$(".accordion p:not(:first)").hide();
	$(".accordion h3").click(function(){
		$(this).next("p").slideToggle("slow")
		.siblings("p:visible").slideUp("slow");
		$(this).toggleClass("active");
		$(this).siblings("h3").removeClass("active");
	});
	//Contornos y menu
	$(function(){
    var jqDockOpts = {align: 'left', duration: 200, labels: 'tc', size: 48, distance: 85};
    $('#jqDock').jqDock(jqDockOpts);
	$('#relevante').corner("round 14px").parent().css('padding', '15px').corner("round 14px");
    });
	//Slider
		var theInt = null;
		var $crosslink, $navthumb;
		var curclicked = 0;
		theInterval = function(cur){
			clearInterval(theInt);
			if( typeof cur != 'undefined' )
				curclicked = cur;
			$crosslink.removeClass("active-thumb");
			$navthumb.eq(curclicked).parent().addClass("active-thumb");
				$(".stripNav ul li a").eq(curclicked).trigger('click');
			theInt = setInterval(function(){
				$crosslink.removeClass("active-thumb");
				$navthumb.eq(curclicked).parent().addClass("active-thumb");
				$(".stripNav ul li a").eq(curclicked).trigger('click');
				curclicked++;
				//Cambiar el 6 con respecto a las imagnes q son
				if( 6 == curclicked )
					curclicked = 0;
			}, 3000);
		};
		$(function(){		
			$("#main-photo-slider").codaSlider();
			
			$navthumb = $(".nav-thumb");
			$crosslink = $(".cross-link");
			
			$navthumb
			.click(function() {
				var $this = $(this);
				theInterval($this.parent().attr('href').slice(1) - 1);
				return false;
			});
			theInterval();
		});	
});
		//Ajax
		function ajaxFunction() {
		  var xmlHttp;
		  try{
			xmlHttp=new XMLHttpRequest();
			return xmlHttp;
		  }
		  catch (e) {
			try {
				xmlHttp=new ActiveXObject("Msxml2.XMLHTTP");
			  return xmlHttp;
			}
			catch (e) {
				try {
					xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
					return xmlHttp;
				  }catch (e) {
					alert("Tu navegador no soporta tecnologia AJAX por favor. Actualicelo o cambie de Navegador.");
					return false;
				  }
				}
			}
		}
		function Enviar(_pagina,capa){
			var ajax;
			ajax = ajaxFunction();
			ajax.open("POST", _pagina, true);
			ajax.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
			ajax.onreadystatechange = function() {
				if (ajax.readyState == 4) {
						document.getElementById(capa).innerHTML=ajax.responseText; 
					 }
					 else{
						document.getElementById(capa).innerHTML='<img src="cargando.gif" style="margin-top: 20%;"/><p>Espere por favor ...</p>' 
					 }
			}
			ajax.send(null);
		}