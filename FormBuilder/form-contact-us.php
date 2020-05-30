<?php

/**
 * FormBuilder render file (embed method D) for form 'contact-us'
 *
 * Instructions
 * ============
 *
 * 1. If not already in place, the contents of this file should be placed in this file:
 *
 *    /site/templates/FormBuilder/form-contact-us.php
 *
 *    When present, FormBuilder will always use this file for $forms->render('contact-us'); calls, rather than
 *    the markup that it generates at runtime.
 *
 * 2. Move the indicated stylesheet <link> tags further-below to your document <head>, to appear when this form
 *    is rendered. You may optionally omit any or all of the stylesheets if you don't think you will need them.
 *    In particular, remove any that duplicate stylesheets you may already be loading (like from CSS frameworks).
 *
 * 3. Also move the indicated Javascript <script> tags below to your <head> or before closing the </body> tag,
 *    to appear when this form will be rendered. You may optionally omit any of the scripts if you don't think
 *    you will need them. In particular, remove any that duplicate scripts you may already be loading (like jQuery
 *    or CSS framework files). We recommend that you always keep the 'form-builder-d.js' script in place.
 *
 * 4. Adjust the form markup below as you see fit. Keep the form field 'name' attributes in tact. Please note that
 *    removing any 'id' or 'class' attributes (or other significant changes to the markup) may interfere with or
 *    disable features provided by FormBuilder for a given field. So be sure to test any changes thoroughly.
 *
 * 5. To render this form, place the following in a template file where you want the form to appear:
 *
 *    echo $forms->render('contact-us');
 *
 * Optional: Steps 2 and 3 above ask you copy <link> and <script> tags in your document <head>. We recommend that
 * you surround them in something like if($page->id == 123) { ... }, so that you are only rendering these assets
 * on the page where the form will be displayed (where '123' is the ID of the page).
 *
 * Please leave the following here
 * ===============================
 * Date: 2020-05-19 14:08:16
 * Hash: 3f108b0a28fd5572c7935a88f555ab5f
 *
 * If you get want to disable an 'out of date' warning from FormBuilder for this file, copy the 'Hash' (like seen
 * above) from the /site/assets/cache/FormBuilder/form-contact-us.php file, and paste to make it replace the hash
 * value that you see above. We also recommend you update the 'Date' for your own reference.
 *
 *
 * Variables provided to this template
 * ===================================
 * @var InputfieldForm $form Form that is being rendered or processed
 * @var FormBuilderProcessor $processor Processor of form
 * @var array $values Existing values of field inputs, indexed by field name
 * @var array $labels Field labels indexed by field name
 * @var array $descriptions Field descriptions indexed by field name
 * @var array $notes Field notes indexed by field name
 * @var array $errors Error messages to display (populated if form had errors)
 * @var bool $submitted This is TRUE when the form has been successfully submitted
 * @var string $successMessage The success message defined with the form (populated on success)
 *
 */
?>

<?php if($submitted): /* When form submitted, show success message */ ?>

	<div id="FormBuilderSubmitted">
		<h3><?php echo $successMessage; ?></h3>
	</div>

<?php else: /* Render the form markup */ ?>
<!-- ProcessWire Form Builder - Copyright 2018 by Ryan Cramer Design, LLC -->
<form id="form-contact" class="FormBuilderFrameworkBasic FormBuilder InputfieldNoFocus InputfieldFormWidths InputfieldForm" name="contact-us" method="post" action="./" data-colspacing="0">

	<?php
	// output error messages
	if(count($errors)) {
		$form->getErrors(true); // reset
		foreach($errors as $error) {
			echo '<p class="error">' . $error . '</p>';
		}
	}
	?>

			<input placeholder="First Name" required id="Inputfield_first_name" name="first_name" type="text" maxlength="2048" />
			<input placeholder="Last Name"  required id="Inputfield_last_name" name="last_name" type="text" maxlength="2048" />
			<input placeholder="Phone"  required id="Inputfield_phone" name="phone" type="tel" maxlength="2048"/>
			<input placeholder="Email"  required id="Inputfield_email" name="email" type="email" maxlength="512" />
			<textarea placeholder="Comments" required id="Inputfield_comments" name="comments" rows="5"></textarea>
			<button class="button" type="submit" name="contact-us_submit" value="<?php echo $labels['contact-us_submit']; ?><!-- Submit -->">
				<?php echo $labels['contact-us_submit']; ?><!-- Submit -->
			</button>

	<?php echo $session->CSRF->renderInput(); ?>
</form>

<?php
if(count($values)) {
	// populate existing values to fields
	echo "<script>FormBuilderD.populate('$form->id', " . json_encode($values) . ");</script>";
}

endif;
?>
