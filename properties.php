<?php foreach ($page->children as $property): ?>
  <article class="section py-4">
    <div class="container">
      <div class="row">
        <section class="col-sm-4">
          <img class="property-image" src="<?= $property->image->url ?>" alt="">
        </section>
        <section class="col-sm-8">
          <h2 class="property-title"><?= $property->title ?></h2>
          <div class="rich-text">
            <?= $property->rich_text ?>
          </div>
          <div class="property-buttons">
            <a href="<?= $property->flyer->url ?>"><i class="fa fa-download"></i> Download Flyer</a>
            <a href="<?= $property->map->url ?>"><i class="fa fa-search"></i> View Map</a>
          </div>
        </section>
      </div>
    </div>
  </article>
<?php endforeach; ?>

<?php if ($page->children->count === 0): ?>
  <article class="section py-4">
    <div class="container">
      <div class="row">
        There are no current listings in the <?= $page->title ?> Region
      </div>
    </div>
  </article>
<?php endif; ?>
