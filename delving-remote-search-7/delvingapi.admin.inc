<?php
// $Id$
/**
 * @file
 * Form builder for Delving Remote-Search API settings.
 *
 * @ingroup forms
 * @see system_settings_form()
 */

header('Content-Type: text/html; charset=utf-8');

function delving_admin_settings($form, &$form_state) {

  $options_do = array('1' => t('true'), '0' => t('false'));
  $options_df = array('1' => t('true'), '0' => t('false'));
  $options_external_link = array('1' => t('Within Drupal'), '0' => t('To the original data provider'), '0' => t('A Delving Framework Portal instance'));
  $form['api-settings'] = array(
    '#type' => 'fieldset',
    '#title' => 'Delving Remote-Search API settings',
  );
  $form['api-settings']['delving_api_remote_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Delving Remote-search API URL'),
    '#description' => t('URL to send search request to. For example: <a href="@api_url">@api_url</a>', array(
      '@api_url' => url(DELVING_API_REMOTE_URL),
    )),
    '#default_value' => variable_get('delving_api_remote_url', DELVING_API_REMOTE_URL),
    '#required' => TRUE,
  );
  $form['api-settings']['delving_api_results_rows'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of rows to return in search results'),
    '#size' => 2,
    '#default_value' => variable_get('delving_api_results_rows', DELVING_API_RESULTS_ROWS),
  );
  $form['search-constraints'] = array(
    '#type' => 'fieldset',
    '#title' => 'Search Constraints',

  );
  $form['search-constraints']['delving_api_digital_object'] = array(
    '#type' => 'radios',
    '#title' => t('Return only results with digital objects'),
    '#default_value' => variable_get('delving_api_digital_object', DELVING_API_DIGITAL_OBJECT),
    '#options' => $options_do,
  );
  $form['search-constraints']['delving_api_counties'] = array(
    '#title' => t('Limit results to these counties only'),
    '#description' => t('Enter a comma separted list of county names to which you wish to limit the search'),
    '#type' => 'textfield',
    '#default_value' => variable_get('delving_api_counties', DELVING_API_COUNTIES),
    '#required' => FALSE,
  );
  $form['search-display-settings'] = array(
    '#type' => 'fieldset',
    '#title' => 'Page Display Settings',
  );
  $form['search-display-settings']['delving_search_page_name'] = array(
    '#type' => 'textfield',
    '#title' => 'Search-page name value',
    '#default_value' => variable_get('delving_search_page_name', DELVING_SEARCH_PAGE_NAME),
    '#required' => TRUE,
    '#description' => t('The name for the Delving-Remote-Search page. This is the name that will show in the menu and the top of the search page')
  );
  $form['search-display-settings']['delving_search_page_return'] = array(
    '#type' => 'textfield',
    '#title' => 'Item page link text',
    '#default_value' => variable_get('delving_search_page_return', DELVING_SEARCH_PAGE_RETURN),
    '#required' => TRUE,
    '#description' => t('The text which appears in the link back to results page')
  );
   $form['search-item-view-settings'] = array(
    '#type' => 'fieldset',
    '#title' => 'Object Display Settings',
  );
   $form['search-item-view-settings']['delving_search_item_view_path'] = array(
    '#type' => 'select',
    '#title'=> t('Choose where you would like to view the object'),
    '#description' => t('All links on the titles of the returned results will point to this setting.'),
    '#default_value' => variable_get('delving_search_item_view_path', DELVING_SEARCH_ITEM_VIEW_PATH),
    '#options' => array(
      'drupal' => t('Within drupal'),
      'isShownAt' => t('In original context from the Dataprovider'),
      'delvingPlatform' => t('A Delving Platform compliant portal'),
    ),
  );
  $form['search-item-view-settings']['delving_search_item_external_url'] = array(
    '#type' => 'textfield',
    '#title' => t('External URL'),
    '#description' => t('URL for an external Delving Platform portal instance. For example "http://norvegiana2.delving.org/portal/object/"'),
    '#default_value' => variable_get('delving_search_item_external_url', DELVING_SEARCH_ITEM_EXTERNAL_URL)
  );
  $form['search-display-settings']['#description'] = '<p>' . t('The display of the Facets blocks ("Refine Search") can be configured on the <strong class="drupal_link_admin_settings"><a href="' . url('admin/structure/block') . '">Blocks Configuration Page</a></strong>.') . '</p>';



  return system_settings_form($form);
}