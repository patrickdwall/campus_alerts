(function ($) {
  Drupal.behaviors.campus_alerts = {
    attach: function (context, settings) {
      $('body').not('.ember').not('.campus-alert-active').once('campus-alerts', function() {
        if (!$('body').hasClass('page-admin-config-content-campus-alerts')) {
          //return;
        }
        // Banner Alert
        $(window).load(function() {
          $('<div class="campus-banner-alert"/>').load('/ajax/campus-alerts/banner', function(response, status, xhr) {
            if (status != 'success' || xhr.responseText == '' || xhr.responseText == 'ok') {
              return;
            }
            $(this).hide().insertAfter('#navigation').slideToggle();
          });
        });

        // Page Alert
        $('<div class="campus-page-alert"/>').load('/ajax/campus-alerts/page', function(response, status, xhr) {
          if (status != 'success' || xhr.responseText == '' || xhr.responseText == 'ok') {
            return;
          }
          var alert = $(this);
          $('.close', alert).click(function() {
            alert.hide();
          });
          $('body').prepend($(this));
        });
      });
    }
  };
})(jQuery);
