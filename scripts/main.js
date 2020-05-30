var main = function() {

  if (document.querySelector("#fader")) {
    var headerImgs = document.querySelectorAll(".fader-img");

    document.querySelector("#fader").style.height = headerImgs[0].clientHeight + "px";

    function resizeFader() {
      document.querySelector("#fader").style.height = headerImgs[0].clientHeight + "px";
      console.log(headerImgs[0].clientHeight + "px");
    }

  //alert(headerImgs[0].clientHeight);

  window.onresize = resizeFader;

    if (headerImgs.length > 1) {
      fadeOut(0);
    }

    function fadeOut(slideId) {
      //if not the last slide
      if (slideId !== headerImgs.length-1) {
        setTimeout(function() {
          headerImgs[slideId].style.animation = "fadeOut 1s forwards";
          headerImgs[0].dataset.visible = "true";
          fadeIn(slideId+1);
        }, 5000);

      } else {
        //this must be the last slide
        setTimeout(function(){
          headerImgs[slideId].style.animation = "fadeOut 1s forwards";
          headerImgs[0].dataset.visible = "true";
          fadeIn(0);
        }, 5000);

      }

    }

    function fadeIn(slideId) {
      //turn on new slide
      headerImgs[slideId].style.animation = "fadeIn 1s forwards";
      //turn off old slide
      headerImgs[0].dataset.visible = "false";

      setTimeout(fadeOut(slideId), 5000);
    }
  }

  //mobile menu

  document.getElementById("mobile-nav-toggle-button").addEventListener("click", function() {
    mobileNavToggle();
  });

  let mobileNavDropdowns = document.querySelectorAll(".mobile-nav-dropdown");

  for (var i = 0; i < mobileNavDropdowns.length; i++) {
    mobileNavDropdowns[i].addEventListener("click", function() {
      openMobileNavDropdown(this);
    });
  }

  function mobileNavToggle() {
      let navPanel = document.getElementById("mobile-nav-panel");
      let icon = document.getElementById("mobile-nav-toggle-icon");
      if (navPanel.dataset.open === "false") {
          navPanel.dataset.open = "true";
          icon.style.animation = "rotateHorizontal 0.75s forwards";
          navPanel.style.animation = "slideInLeft 0.75s forwards";
      } else {
          navPanel.dataset.open = "false";
          icon.style.animation = "rotateVertical 0.75s forwards";
          navPanel.style.animation = "slideOutRight 0.75s forwards";
      }
  }

  function openMobileNavDropdown(el) {
      let id = el.dataset.mobileDropdownId;
      if (document.getElementById("mobile-nav-panel-" + id).dataset.open === "false") {
          document.getElementById("mobile-nav-panel-" + id).dataset.open = "true";
          document.getElementById("mobile-nav-panel-" + id).style.display = "flex";
      } else {
          document.getElementById("mobile-nav-panel-" + id).dataset.open = "false";
          document.getElementById("mobile-nav-panel-" + id).style.display = "none";
      }
  }

} // end main
