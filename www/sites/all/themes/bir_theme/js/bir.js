
// for superfish menus
jQuery(function(){
  jQuery('ul.sf').superfish( {
    delay:500,
    autoArrows:false,
    dropShadows:false
  });
  
  // If browse page, get user albums
  if (jQuery('#bulkAlbumFrm').length > 0) {
    jQuery.post("/bir_album/ajax/get-user-albums", 
      function(data) {
        jQuery.each(data, function(key, value) {
          jQuery('#bulkActionSelect')
            .append(jQuery('<option>', { value : key })
            .text(value)); 
        });
      }, 'json');
  }
  
  // Check/uncheck all button for albums
  jQuery('.check:button').toggle(
    function(){
      jQuery("input[name='nid[]']").attr('checked','checked');
      jQuery(this).val('Uncheck All')
    },
    function(){
      jQuery("input[name='nid[]']").removeAttr('checked');
      jQuery(this).val('Check All');        
  })
  
  // Function for bulk collection operations
  jQuery('#bulkAlbumFrm').submit(function(event) {
    event.preventDefault();
    var value = jQuery('#bulkActionSelect').val();
    if (value == '') return;
    
    var nids = new Array();
    jQuery.each(jQuery("input[name='nid[]']:checked"), function() {
      nids.push(jQuery(this).val());
    });
    if (nids.length == 0) {
      alert("Please select at least one object.");
      jQuery(this).val("");
      return;
    }
    
    switch (value) {
      case 'create': // Create a new bir album
        window.location = "/node/add/bir-album?bir_album_node="+nids;
        break;
      default: // Add to bir album
        window.location = "/node/"+value+"/edit?bir_album_node="+nids;
        break;
    }
  });
  
  jQuery('#edit-view-id-und-0-target-id').blur(function(){
    var val = jQuery(this).val();
    jQuery.post("/bir_view/ajax/autofill-view", { "val": val },
      function(data){
        jQuery.each(data, function(key, val) {
          if (key == 'view_title') {
            jQuery('input[name^="'+key+'"]').val(val);
          } else {
            jQuery('select[name^="'+key+'"]').val(val);
          }
        });
      }, "json");
  });
  
  // prevent geolocation submit if using enter key in autocomplete
  jQuery('input[id^="edit-locality-id"]').keydown(function(event){
    if ( event.keyCode == 13 ) event.preventDefault();
  });
  
  jQuery('#edit-locality-id-und-0-target-id').blur(function(){
    var val = jQuery(this).val();
    jQuery.post("/bir_locality/ajax/autofill-locality", { "val": val },
      function(data){
        var trigger = false;
        jQuery.each(data, function(key, val) {
          jQuery('input[id^="'+key+'"]').val(val);
          if (key == 'trigger' && val == true) trigger = true;
        });
        if (trigger) 
          jQuery('input[id^="getlocations_geocodebutton"]').click();
      }, "json");
  });
  
  if (jQuery('#edit-name').length > 0)
    jQuery('#edit-name').focus();
  
});
