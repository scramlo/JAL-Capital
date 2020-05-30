<?php foreach ($page->team_members as $team_member): ?>
  <article class="section py-4">
    <div class="container">
      <div class="row">
        <div class="col-12">
          <h2 class="team-member-name"><?=  $team_member->team_member_name ?></h2>
        </div>
      </div>
      <div class="row">
        <section class="col-3">
          <img class="team-member-image" src="<?= $team_member->image_left->size(300,350)->url ?>" alt="Image of <?= $page->team_member_name ?>">
        </section>
        <section class="col-9">
          <div class="rich-text">
            <?= $team_member->rich_text ?>
          </div>
        </section>
      </div>
    </div>
  </article>
<?php endforeach; ?>

<?php if ($page->team_members->count === 0): ?>
  <article class="section py-4">
    <div class="container">
      <div class="row">
        There are no team members to view.
      </div>
    </div>
  </article>
<?php endif; ?>
