<?php
/**
 * @file
 * Theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/garland.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlight']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 * - $page['bottom']: Items to appear at the bottom of the page below the footer.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see zen_preprocess_page()
 * @see template_process()
 */
$variables = array(
    'path' => '/sites/all/themes/bir_theme/images/creativecommons.png',
    'alt' => 'Creative Commons',
    'attributes' => array('width' => 88, 'height' => 31),
);
$creativecommons = theme('image', $variables);
?>


<?php
//display a page without header, footer and regions
if (isset($_GET["format"]) && $_GET["format"] == "simple") {
  include ('page-node-simple.tpl.php');
  return;
}
?>
<div id="page-wrapper"><div id="page">
    <div id="header"><div class="section clearfix">
        <div id="nav">
          <div id="navmain">
            <ul class="sf sf-js-enabled">
              <li class="nav-home"><a href="/" title="Home Images"><span>Home</span></a></li>
              <li class="nav-browse"><a href="/browse" title="Browse Images"><span>Browse</span></a>
                <ul style="display: none; visibility: hidden; ">
                  <li><a href="<?php print $base_path ?>browse?f[0]=type:bir_image"><span>Images</span></a></li>
                  <li><a href="/browse?f[0]=type:bir_specimen"><span>Specimens</span></a></li>
                  <li><a href="/browse?f[0]=type:bir_locality"><span>Localities</span></a></li>
                  <li><a href="/browse?f[0]=type:bir_view"><span>Views</span></a></li>
                  <li><a href="/browse?f[0]=type:bir_album"><span>Albums</span></a></li>
                  <li><a href="/browse-map-all"><span>Map All</span></a></li>
                </ul>
              </li>
              <li class="nav-tools"><a href="#" title="Tools"><span>Tools</span></a>
                <?php if ($logged_in) { ?>
                  <ul style="display: none; visibility: hidden; ">
                    <li><a href="/node/add/bir-image"><span>Single Image upload</span></a></li>
                    <li><a href="/node/add/bir-specimen"><span>Single Specimen upload</span></a></li>
                    <li><a href="/node/add/bir-locality"><span>Single Locality upload</span></a></li>
                    <li><a href="/node/add/bir-view"><span>Single View upload</span></a></li>
                    <li><a href=""><span>Bulk upload</span></a></li>
                    <li><a href=""><span>Web Services</span></a></li>
                  </ul>
                <?php } ?>
              </li>
              <li class="nav-feedback"><a href="/contact" title="Feedback"><span>Feedback</span></a></li>
              <li class="nav-about"><a href="#" title="About"><span>About</span></a>
                <ul style="display: none; visibility: hidden; ">
                  <li><a href="/about-morphbank"><span>About Morphbank</span></a></li>
                  <li><a href="/about-ala"><span>About ALA</span></a></li>
                </ul></li>
              <li class="nav-help"><a href="#" title="Help"><span>Help</span></a>
                <ul style="display: none; visibility: hidden; ">
                  <li><a href="/online-user-manual"><span>Online User Manual</span></a></li>
                  <li><a href="/how-contribute-data"><span>How to submit data</span></a></li>
                  <li><a href="/sitemap"><span>Sitemap</span></a></li>
                </ul></li>
          </div>
          <div id="navmain2">
            <ul class="sf sf-js-enabled">
              <?php if ($logged_in): ?>
                <li class="nav-logout"><a href="/user/logout"><span>Log out</span></a></li>
              <?php else: ?>
                <li class="nav-login"><a href="/user"><span>Log in</span></a></li>
                <li class="nav-register"><a href="/user/register"><span>Register</span></a></li>
              <?php endif; ?>
            </ul>
            <br /><br /><br />
            <?php if ($user->uid): global $user; ?>
              <font color="white">Logged in as: <strong><?php print $user->name; ?></strong></font>
            <?php else: ?>
              <font color="white">Welcome Guest</font>
            <?php endif; ?>
          </div>
          <div id="navmain3">
            <ul class="sf sf-js-enabled">
              <li class="nav-mymanager"><a href="/my-manager"><span>My Manager</span></a></li>
              <li class="nav-myalbums"><a href="/my-albums"><span>My Albums</span></a></li>
            </ul>
          </div>
          <!-- Morphbank custom header -->
          <a href="/home" title="<?php print t('Home'); ?>" rel="home" id="logo"><img src="<?php print t($base_path); ?><?php print t($directory); ?>/images/ala_logo.png" alt="<?php print t('Home'); ?>" /></a>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo"><img hspace="6" src="<?php print t($base_path); ?><?php print t($directory); ?>/images/mb_tab_logo2.png" alt="<?php print t('Home'); ?>" /></a>
        </div>
        <?php //print t($directory); ?>
        <?php if ($site_slogan): ?>
          <div id="site-slogan">
            <?php print $site_slogan; ?></div>
        <?php endif; ?>
        <?php print render($page['header']); ?>
      </div></div> <!-- /.section, /#header -->
    <div id="main-wrapper">
      <div id="main" class="clearfix<?php if ($main_menu || $page['navigation']) {
          print ' with-navigation';
        } ?>">
        <div id="content" class="column"><div class="section">
            <?php print render($page['highlight']); ?>
            <?php print $breadcrumb; ?>
            <a id="main-content"></a>
            <?php print render($title_prefix); ?>
            <?php if ($title): ?>
              <h1 class="title" id="page-title"><?php print $title; ?></h1>
            <?php endif; ?>
            <?php print render($title_suffix); ?>
            <?php print $messages; ?>
            <?php if ($tabs): ?>
              <div class="tabs"><?php print render($tabs); ?></div>
            <?php endif; ?>
            <?php print render($page['help']); ?>
            <?php if ($action_links): ?>
              <ul class="action-links"><?php print render($action_links); ?></ul>
            <?php endif; ?>
        <?php print render($page['content']); ?>
        <?php print $feed_icons; ?>
          </div></div> <!-- /.section, /#content -->
            <?php if ($page['navigation'] || $main_menu): ?>
          <div id="navigation"><div class="section clearfix">
              <?php
              print theme('links__system_main_menu', array(
                          'links' => $main_menu,
                          'attributes' => array(
                              'id' => 'main-menu',
                              'class' => array('links', 'clearfix'),
                          ),
                          'heading' => array(
                              'text' => t('Main menu'),
                              'level' => 'h2',
                              'class' => array('element-invisible'),
                          ),
                      ));
              ?>

          <?php print render($page['navigation']); ?>

            </div></div> <!-- /.section, /#navigation -->
        <?php endif; ?>

<?php print render($page['sidebar_first']); ?>

<?php print render($page['sidebar_second']); ?>

      </div></div> <!-- /#main, /#main-wrapper -->

    <div id="footer">
      <div id="footer-nav">
        <ul id="menu-footer-legal">
          <li><a href="/terms-use">Terms of Use</a></li>
          <li><a href="/citing-atlas">Citing the Atlas</a></li>
          <li><a href="/copyright">Copyright</a></li>
          <li><a href="/licensing">Licensing</a></li>
        </ul>
      </div>

      <div class="copyright">
        <p><a href="http://creativecommons.org/licenses/by/3.0/au/" title="External link to Creative Commons" id="CCicon"><?php print $creativecommons; ?></a>This site is licensed under a <a href="http://creativecommons.org/licenses/by/3.0/au/" title="External link to Creative Commons">Creative Commons Attribution 3.0 Australia License</a> - Provider content may be covered by other <span class="asterisk-container"><a href="/terms-use#other-terms" title="Terms of Use">Terms of Use</a>.</span></p>
      </div>

    </div>

    <!-- /.section, /#footer -->
  </div></div> <!-- /#page, /#page-wrapper -->
<?php print render($page['bottom']); ?>
