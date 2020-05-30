<?php
  $nav_line = "
  <svg class='nav-line'>
    <line x1='0' y1='37' x2='21' y2='0' />
  </svg>
  ";
?>

<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Home - <?= $page->title ?></title>
    <link rel="stylesheet" href="<?php echo AIOM::CSS(array('styles/bootstrap-grid.css','styles/fa/font-awesome.less','styles/utilities.less','styles/main.less')); ?>">
    <style media="screen">
    #mobile-nav-toggle-button {
      width: 0.25rem;
      transform: rotate3d(0,0,0,0);
      cursor: pointer;
      padding: 1rem;
    }

    #mobile-nav-panel {
      height:100%;
      width:100vw;
      position: fixed;
      left:100vw;
      opacity: 0;
      background-color: white;
      z-index: 1000;
    }

    #mobile-nav-panel .btn {
      margin: 2rem;
      width:85vw;
    }

    #mobile-nav-panel>nav {
      display: flex;
      flex-direction: column;
      width: 100%;
      padding: 3rem;
    }

    #mobile-nav-panel>nav a {
      padding: 1rem 0rem;
      font-size: 2rem;
    }

    .mobile-nav-dropdown-panel {
      display: flex;
      flex-direction: column;
      display: none;
    }

    .mobile-nav-dropdown-panel a {
      margin-left: 2rem;
    }

    .mobile-nav-dropdown-panel a:hover {
      margin-left: 2rem;
    }

    .mobile-nav-dropdown {
      cursor: pointer;
    }

    @keyframes slideInLeft {
        from {
          opacity: 1;
          left:100vw;
        }

        to {
          opacity: 1;
          left:0;
          }
      }

      @keyframes slideOutRight {
        from {
          opacity: 1;
          left: 0;
        }

        to {
          opacity: 1;
          left:100vw;
          }
      }

      @keyframes rotateHorizontal {
        from {
          transform: rotate3d(0,0,0,0);
        }

        to {
          transform: rotate3d(0,0,1,90deg);
        }
      }

      @keyframes rotateVertical {
        from {
          transform: rotate3d(0,0,1,90deg);
        }

        to {
          transform: rotate3d(0,0,0,0);
        }
      }

      /* Large devices (desktops, 992px and up) */
      @media (min-width: 992px) {

        #nav-header {

        }

        #desktop-navigation, #nav-right {
          display: block;
          padding-right: 1rem;
        }

        #mobile-nav-toggle-button {
          display: none;
        }
      }

    </style>
  </head>
  <body onload="main()">

    <!-- DESKTOP NAVIGATION -->
    <section class="container pt-3">
      <div id="nav-wrapper" class="row">
        <div class="col-4">
          <a href="<?= $pages->get("/")->url ?>">
          <img id="logo" src="<?= $pages->get("template=site-options")->logo->url ?>" title="JAL Capital Logo" alt="JAL Capital Logo">
        </a>
        </div>
        <?php $active = "class='active'"; ?>
        <nav id="main-nav" class="col-8 d-none d-lg-block text-right">
          <a <?= $page->template->name === "home" ? $active : "" ?> href="<?= $pages->get("/")->url ?>">Home</a>
          <?= $nav_line ?>
          <?php foreach ($pages->get("/")->children as $link): ?>
            <?php if ($link->template->name === "parent_link"): ?>
              <a <?= $page->url === $link->child()->url ? $active : "" ?>href="<?= $link->child()->url ?>" title="Link to <?= $link->title ?>" alt="Link to <?= $link->title ?>"><?= $link->title ?></a>
            <?php else: ?>
              <a <?= $page->url === $link->url ? $active : "" ?>href="<?= $link->url ?>" title="Link to <?= $link->title ?>" alt="Link to <?= $link->title ?>"><?= $link->title ?></a>
            <?php endif; ?>
            <?= $link->id === $pages->get("/")->children->last()->id ? "" : $nav_line ?>
          <?php endforeach; ?>
        </nav>
        <aside class="col-8 d-lg-none text-right">
          <a id="mobile-nav-toggle-button">
            <svg version="1.1" id="mobile-nav-toggle-icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
            	 viewBox="0 0 512 512" style="width: 1rem" xml:space="preserve">
              <g>
              	<g>
              		<g>
              			<circle cx="256" cy="256" r="64"/>
              			<circle cx="256" cy="448" r="64"/>
              			<circle cx="256" cy="64" r="64"/>
              		</g>
              	</g>
              </g>
              <g>
              </g>
              <g>
              </g>
              <g>
              </g>
              <g>
              </g>
              <g>
              </g>
              <g>
              </g>
              <g>
              </g>
              <g>
              </g>
              <g>
              </g>
              <g>
              </g>
              <g>
              </g>
              <g>
              </g>
              <g>
              </g>
              <g>
              </g>
              <g>
              </g>
            </svg>
          </a>
        </aside>
      </div>

    </section>
    <?php if (($page->id !== 1) && ($page->parent->template->name === "parent_link")): ?>
      <section id="sub-nav-wrapper">
        <div class="container">
          <div class="row">
            <?php $active = " sub-active"; ?>
            <nav id="sub-nav" class="col-12 d-none d-lg-flex">
              <?php foreach ($page->parent->children as $link): ?>
                <div class="sub-container<?= $page->url === $link->url ? $active : "" ?>">
                  <span class="sub-link-hidden-text"><?= $link->title ?></span>
                  <a href="<?= $link->url ?>" title="Link to <?= $link->title ?>" alt="Link to <?= $link->title ?>"><?= $link->title ?></a>
                </div>
              <?php endforeach; ?>
            </nav>
          </div>
        </div>
      </section>
    <?php endif; ?>
    <!-- END DESKTOP NAVIGATION -->

    <!-- MOBILE NAVIGATION -->
    <div id="mobile-nav-panel" data-open="false">
      <nav>
        <a title="Home" href="<?= $pages->get("/")->url ?>">Home</a>
        <?php foreach ($pages->get("/")->children as $link): ?>
          <?php if ($link->template->name !== "parent_link"): ?>
            <a href="<?= $link->url ?>" title="<?= $link->title ?>"><?= $link->title ?></a>
          <?php else: ?>
            <a data-mobile-dropdown-id="<?= $link->id ?>"class="mobile-nav-dropdown" title="<?= $link->title ?>"><?= $link->title ?> <i class="fa fa-caret-down"></i></a>
            <div data-open="false"  id="mobile-nav-panel-<?= $link->id ?>" class="mobile-nav-dropdown-panel">
              <?php foreach ($link->children as $child_link): ?>
                <a title="<?= $child_link->title ?>" href="<?= $child_link->url ?>"><?= $child_link->title ?></a>
              <?php endforeach; ?>
            </div>
          <?php endif; ?>
        <?php endforeach; ?>
      </nav>
    </div>
    <!-- END MOBILE NAVIGATION -->

    <header>
      <div id="fader">

      <?php if ($page->featured_images->count() > 1): ?>
        <img
          src="<?= $page->featured_images->first()->size(1920,800)->url ?>"
          class="fader-img"
          data-visible="true"
          alt="Featured Image for <?= $page->title ?>"
         >
         <img
           src="<?= $page->featured_images->last()->size(1920,800)->url ?>"
           class="fader-img"
           data-visible="false"
           alt="Featured Image for <?= $page->title ?>"
          >
      <?php else: ?>
        <img
          src="<?= $page->featured_images->first()->size(1920,800)->url ?>"
          class="fader-img"
          alt="Featured Image for <?= $page->title ?>"
         >
      <?php endif; ?>
      <?php
        if ($page->featured_property):
        $featured = $page->featured_property;
      ?>
        <aside id="featured-aside" class="d-none d-lg-block">
          <div id="featured-aside-content">
            <h2 id="featured-aside-heading">Featured Property</h2>
            <?= $page->children->first() ?>
            <p id="featured-aside-title"><?= $sanitizer->truncate($featured->title, 150) ?></p>
            <p id="featured-aside-text"><?= $sanitizer->truncate($featured->rich_text, 150, "sentence") ?></p>
            <div id="featured-aside-property-buttons" class="property-buttons">
              <a href="<?= $featured->flyer->url ?>"><i class="fa fa-download"></i> Flyer</a>
              <a href="<?= $featured->map->url ?>"><i class="fa fa-search"></i> Map</a>
            </div>
          </div>
        </aside>
      <?php endif; ?>
      </div>
    </header>
    <main class="py-4">
      <div class="container">
        <div class="row">
          <div class="col-12">
            <h1><?= $page->title ?></h1>
          </div>
        </div>
      </div>
