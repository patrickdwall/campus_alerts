<?php
/**
 * @file
 * Campus Alerts module.
 */

/**
 * Form callback: Campus Alerts Settings
 */
function campus_alerts_settings_form($form, &$form_state) {
  $form['banner'] = array(
    '#tree' => FALSE,
    '#type' => 'fieldset',
    '#title' => t('Banner Alert'),
  );

  $form['banner']['campus_alerts_banner_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => variable_get('campus_alerts_banner_enabled', NULL),
  );

  $form['banner']['campus_alerts_banner_level'] = array(
    '#type' => 'select',
    '#title' => t('Level'),
    '#options' => array(
      'status' => t('Status'),
      'warning' => t('Warning'),
      'alert' => t('Alert'),
    ),
    '#default_value' => variable_get('campus_alerts_banner_level', NULL),
  );

  $var = variable_get('campus_alerts_banner_text', array('value' => ''));
  $form['banner']['campus_alerts_banner_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Text'),
    '#format' => 'full_html',
    '#default_value' => $var['value'],
  );

  $form['page'] = array(
    '#tree' => FALSE,
    '#type' => 'fieldset',
    '#title' => t('Page Alert'),
  );

  $form['page']['campus_alerts_page_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => variable_get('campus_alerts_page_enabled', NULL),
  );

  $var = variable_get('campus_alerts_page_text', array('value' => ''));
  $form['page']['campus_alerts_page_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Text'),
    '#format' => 'full_html',
    '#default_value' => $var['value'],
  );

  return system_settings_form($form);
}