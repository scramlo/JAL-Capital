    </main>
    <footer>
      <div class="container">
        <div class="row">
          <div class="col-12">
            <address>
              <?= $pages->get("template=site-options")->contact_info ?>
            </address>
          </div>
        </div>
        <div class="row my-3">
          <div class="col-12">
            <nav class="link-list">
              <a href="<?= $pages->get("/")->url ?>">Home</a>
              <?php foreach ($pages->get("/")->children as $link) {
                if ($link->template->name !== "parent_link") {
                  echo "<a href='$link->url' title='$link->title'>$link->title</a>";
                } else {
                  echo "<a href='{$link->child->url}' title='$link->title'>$link->title</a>";
                }
              } ?>
            </nav>
          </div>
        </div>
        <div class="row">
          <div class="col-sm-6">
            <small>Copyright © <?= date("Y"); ?> JAL Capital Real Estate Partners, LLC</small>
          </div>
          <div class="col-sm-6 text-md-right">
            <small>Handcrafted by <a href="https://nerdspecs.com">Nerd Specs Creative</a></small>
          </div>
        </div>
      </div>
    </footer>

    <script src="<?php echo AIOM::JS(array('scripts/main.js')); ?>"></script>

    <?php if ($page->template == "contact"): ?>
      <script type="text/javascript">var _pwfb={ config:<?php echo json_encode(array_merge($config->js(),array("urls"=>array("root"=>$config->urls->root),"debug" => $config->debug)));?>};if(typeof ProcessWire=="undefined"){var ProcessWire=_pwfb;}else{for(var _pwfbkey in _pwfb.config) ProcessWire.config[_pwfbkey] = _pwfb.config[_pwfbkey];}if(typeof config=="undefined"){var config=ProcessWire.config;}_pwfb=null;</script>
      <script src='<?php echo $config->urls->root; ?>wire/modules/Jquery/JqueryCore/jquery-1.11.1.js'></script>
      <script src='<?php echo $config->urls->root; ?>wire/templates-admin/scripts/inputfields.min.js'></script>
      <!-- This next script (form-builder-d.js) must go either in the document head or somewhere before the <form> -->
      <script src='<?php echo $config->urls->FormBuilder; ?>form-builder-d.js'></script>
    <?php endif; ?>

  </body>
</html>
