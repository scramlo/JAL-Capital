<article class="container py-2">
  <div class="row">
    <?php $num = "12" ?>
    <?php if ($page->image_left): ?>
    <div class="text-center col-12 col-md-3">
      <img class="image-left" src="<?= $page->image_left->size(500,500)->url ?>" alt="Image of <?= $page->image_left->title ?>">
    </div>
    <?php
      $num = "9";
      endif;
    ?>
    <div class="rich-text col-12 col-md-<?= $num ?> lead">
      <?= $page->rich_text ?>
    </div>
  </div>
</article>
